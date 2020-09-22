// 20200922 jpd
// Quick and dirty Topaz DAQ to tsv

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "DIMHW.h"

#define PRESET_TIME 5	// time per daq cycle in secxonds
#define CHANNELS 4096

int main( int argc, char **argv ) {

// Assume exactly one Topaz MCA attached, get its handle.

	int code = FindDevicesEx( DEF_MCA_INTFC_ALL, 1000, true );
	if( code <= 0 ) {
		fprintf( stderr, "Can't access MCA.\n" );
		exit( 1 );
	}
	char 	mca_path[ DEF_MCA_STRING_LENGTH ],
		mca_name[ DEF_MCA_STRING_LENGTH ],
		mca_serial[ DEF_MCA_STRING_LENGTH ];
	int32_t mca_type;
	code = GetDeviceInfo( 
		0, 
		mca_path, DEF_MCA_STRING_LENGTH,
		mca_name, DEF_MCA_STRING_LENGTH,
		mca_serial, DEF_MCA_STRING_LENGTH,
		&mca_type );
	if( code != MCA_SUCCESS ) {
		fprintf( stderr, "Can't get MCA info, code %d\n", code );
		exit( 1 );
	}
	HANDLE mca;
	code = OpenDevice( mca_path, mca_type, &mca );
	if( code != MCA_SUCCESS ) {
		fprintf( stderr, "Can't open MCA, code %d\n", code );
		exit(1);
	}

// Set up timed acquisition
	
	int intp = DEF_MCA_ACQ_MODE_REAL_TIME | DEF_MCA_ACQ_MODE_TIME;
	code = SetParam( mca, DEF_MCA_PARAM_ACQ_MODE_EX, 
		&intp, sizeof( intp ));
	if( code != MCA_SUCCESS ) {
		fprintf( stderr, "Can't set acquisition mode, code %d\n", 
			code );
		exit( 1 );
	}
	float floatp = PRESET_TIME;	// time in seconds
	code = SetParam( mca, DEF_MCA_PARAM_PRESET_TIME, 
		&floatp, sizeof( floatp ));
	if( code != MCA_SUCCESS ) {
		fprintf( stderr, "Can't set acquisition time, code %d\n", 
			code );
		exit( 1 );
	}

// Make sure we have the channels right

	int channels = CHANNELS;
	code = SetParam( mca, DEF_MCA_PARAM_NUM_CHANNELS, 
		&channels, sizeof( channels ));
	if( code != MCA_SUCCESS ) {
		fprintf( stderr, "Can't set channels, code %d\n", code );
		exit( 1 );
	}

// Collect and report until interrupted.
	
	for( ;; ) {
	
	// Start with a clean slate
	
		code = ClearAll( mca );
		if( code != MCA_SUCCESS ) {
			fprintf( stderr, "Can't clear data, code %d\n", code );
			exit( 1 );
		}
		
	// Take some data
	
		code = StartAcquisition( mca );
		if( code != MCA_SUCCESS ) {
			fprintf( stderr, "Can't start acquisition, code %d\n",
			 	code );
			exit( 1 );
		}
	
		time_t now = time( NULL );
		printf( "START\t%ld\t%s", now, asctime( gmtime( &now )));
	
	// Sleep until almost done, then poll until done.
	
		sleep( PRESET_TIME - 1 );
		uint32_t status;
		do {
			code = GetAcquisitionStatus( mca, &status );
				if( code != MCA_SUCCESS ) {
				 fprintf( stderr, 
				 	"Can't get status, code %d\n", code );
				exit( 1 );
			}
		} while( status != DEF_MCA_ACQ_STATUS_STOPPED );
	
	// Read spectrum
		uint32_t spectrum[ CHANNELS ];
		uint32_t channels;
		float elapsed, live;
		code = ReadSpectrum( mca, spectrum, &channels, 
			&elapsed, 
			&live );
		if( code != MCA_SUCCESS ) {
			fprintf( stderr, "Can't read spectrum, code %d\n",
			 	code );
			exit( 1 );
		}
		
	// Read external counts
		int ext;
		code = GetParam( mca, DEF_MCA_PARAM_EXT_COUNTS,
			&ext, sizeof(ext));
		if( code != MCA_SUCCESS ) {
			fprintf( stderr, "Can't read ext counts, code %d\n",
			 	code );
			exit( 1 );
		}
	
	// Read PHA triggers
		int triggers;
		code = GetParam( mca, DEF_MCA_PARAM_ICR_COUNTS,
			&triggers, sizeof(ext));
		if( code != MCA_SUCCESS ) {
			fprintf( stderr, "Can't read triggers, code %d\n",
			 	code );
			exit( 1 );
		}
		
	// Output
	
		printf( "ELAPSED\t%f\n", elapsed );
		printf( "LIVE\t%f\n", live );
		printf(	"TRIG\t%d\n", triggers );
		printf( "EXT\t%d\n", ext );
		
		int chan;
		for( chan = 0; chan < channels; chan += 1 ) 
			if( spectrum[chan] > 0 )
				printf( "PHA\t%d\t%d\n", 
					chan, spectrum[chan] );
		fflush( stdout );
	}
}
