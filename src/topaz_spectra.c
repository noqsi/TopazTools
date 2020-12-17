#include "twrap.h"
#include <time.h>

int main( int argc, char **argv ) {

	HANDLE mca = openTopaz();

	printf( "TOPAZ\t%s\t%s\n", Topaz_serial(), Topaz_name() );
	printf( "DIGITAL_GAIN\t%d\n",
		1<<read_Topaz_int( DEF_MCA_PARAM_GAIN_DIGITAL ) );	
	printf( "COARSE_GAIN\t%d\n",
		1<<read_Topaz_int( DEF_MCA_PARAM_GAIN_COARSE ) );
	printf( "FINE_GAIN\t%f\n",
		(read_Topaz_int( DEF_MCA_PARAM_GAIN_FINE ) + 4096 )/4096.0 );
	printf( "THRESHOLD\t%d\n",
		read_Topaz_int( DEF_MCA_PARAM_THRESHOLD ) );
	double us = 1.0e6/read_Topaz_int( DEF_MCA_PARAM_ADC_SAMPLING_RATE );
	printf( "RISE\t%f\n",
		us * read_Topaz_int( DEF_MCA_PARAM_RISE_TIME ) );
	printf( "FLAT\t%f\n",
		us * read_Topaz_int( DEF_MCA_PARAM_FLAT_TOP ) );
	int hvstat = read_Topaz_int( DEF_MCA_PARAM_HV_STATUS );
	if ( hvstat & 0x8 ) {
		fprintf( stderr, "HV fault\n" );
		exit( 1 );
	}
	if( !hvstat ) printf( "HV\tOFF\n" );
	else printf( "HV\t%f\n", 
		read_Topaz_float( DEF_MCA_PARAM_HV_VALUE ) );
	float integration_time = 
		read_Topaz_float( DEF_MCA_PARAM_PRESET_TIME );
	printf( "INTEGRATION_TIME\t%f\n", integration_time );
	uint32_t channels = 
		read_Topaz_int( DEF_MCA_PARAM_NUM_CHANNELS );
	printf( "CHANNELS\t%d\n", channels );

	uint32_t *spectrum = calloc( sizeof( uint32_t ), channels );
		
// Collect and report until interrupted.
	
	for( ;; ) {
	
	// Start with a clean slate
	
		int code = ClearAll( mca );
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
	
		sleep( (int) integration_time - 1 );
		
		uint32_t status;
		do {
			code = GetAcquisitionStatus( mca, &status );
				if( code != MCA_SUCCESS ) {
				 fprintf( stderr, 
				 	"Can't get status, code %d\n", code );
				exit( 1 );
			}
		} while( status != DEF_MCA_ACQ_STATUS_STOPPED );


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
		int ext = read_Topaz_int( DEF_MCA_PARAM_EXT_COUNTS );
	
	// Read PHA triggers
		int triggers = read_Topaz_int( DEF_MCA_PARAM_ICR_COUNTS );
		
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
	
