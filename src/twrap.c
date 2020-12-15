// Covenience functions for making a single Topaz operate on a Pi
// For success-oriented callers just print a message and exit on errors.

#include "twrap.h"

static HANDLE mca;
static char 	mca_path[ DEF_MCA_STRING_LENGTH ],
		mca_name[ DEF_MCA_STRING_LENGTH ],
		mca_serial[ DEF_MCA_STRING_LENGTH ];
static int32_t mca_type;
static int isopen;

static void openTopaz( void ) {
	
	if( isopen ) return

// Assume exactly one Topaz MCA attached, get its handle.

	int code = FindDevicesEx( DEF_MCA_INTFC_LIBUSB, 1000, true );
	if( code <= 0 ) {
		fprintf( stderr, "Can't access MCA.\n" );
		exit( 1 );
	}
	if( code != 1 ) {
		fprintf( stderr, "Expecting one Topaz, found %d", code );
		exit( 1 );
	}
	
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
	
	code = OpenDevice( mca_path, mca_type, &mca );
	if( code != MCA_SUCCESS ) {
		fprintf( stderr, "Can't open MCA, code %d\n", code );
		exit(1);
	}
}

int32_t read_Topaz_int( int32_t paramid ) {
	int32_t p;
	
	openTopaz();
	int code = GetParam( mca, paramid, &p, sizeof(p));
	if( code != MCA_SUCCESS ) {
		fprintf( stderr, "Can't get param %d, code %d\n", 
			paramid, code );
		exit(1);
	}
	
	return p;
}

void write_Topaz_int( int32_t paramid, int32_t p ) {
	
	openTopaz();
	int code = SetParam( mca, paramid, &p, sizeof(p));
	if( code != MCA_SUCCESS ) {
		fprintf( stderr, "Can't set param %d to %d, code %d\n", 
			paramid, p, code );
		exit(1);
	}
	
	return;
}

const char *Topaz_name( void ) { return mca_name }
const char *Topaz_serial( void ) { return mca_serial }
