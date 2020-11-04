#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include "DIMHW.h"

int main( int argc, char **argv ) {

	float volts;
	if( argc != 2 || sscanf( argv[1], "%f", &volts ) != 1 ) {
		fprintf( stderr, "usage: topaz_hv volts\n");
		exit( 1 );
	}
	
	if( volts > HV_LIMIT ) {
		fprintf( stderr, 
			"Voltage greater than %f not allowed\n", HV_LIMIT );
		exit( 1 );
	}
	if( volts < 0.0 ) {
		fprintf( stderr, "Negative voltage not supported.\n" );
		exit( 1 );
	}

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
	
	int intp = 0;	// Turn HV off, clearing any fault
	code = SetParam( mca, DEF_MCA_PARAM_HV_STATUS, 
		&intp, sizeof( intp ));
	if( code != MCA_SUCCESS ) {
		fprintf( stderr, "Can't turn HV off, code %d\n", 
			code );
		exit( 1 );
	}

	code = SetParam( mca, DEF_MCA_PARAM_HV_VALUE, 
		&volts, sizeof( volts ));
	if( code != MCA_SUCCESS ) {
		fprintf( stderr, "Can't set HV to %f, code %d\n", 
			volts, code );
		exit( 1 );
	}
	
	if( volts == 0.0 ) exit( 1 );   // leave HV off for zero volts

	intp = 1;	// Turn HV on
	code = SetParam( mca, DEF_MCA_PARAM_HV_STATUS, 
		&intp, sizeof( intp ));
	if( code != MCA_SUCCESS ) {
		fprintf( stderr, "Can't turn HV on, code %d\n", 
			code );
		exit( 1 );
	}
}
