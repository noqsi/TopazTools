#include "twrap.h"

int main( int argc, char *argv[] ) {
	
	int gain, log_gain;
	if( argc != 2 || sscanf( argv[1], "%d", &gain ) != 1 ) {
		fprintf( stderr, "usage: topaz_coarse_gain gain\n");
		exit( 1 );
	}
	
	switch( gain ) {
	
	case 1 : log_gain = 0;
		break;
	case 2 : log_gain = 1;
		break;
	case 4 : log_gain = 2;
		break;
	case 8 : log_gain = 3;
		break;
	default :
		fprintf( stderr, "Coarse gain must be 1, 2, 4, or 8.\n" );
		exit( 1 );
	}
	

	write_Topaz_int( DEF_MCA_PARAM_GAIN_COARSE, log_gain );
	return 0;
}
