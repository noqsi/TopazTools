#include "twrap.h"

int main( int argc, char *argv[] ) {
	
	int gain;
	if( argc != 2 || sscanf( argv[1], "%d", &gain ) != 1 ) {
		fprintf( stderr, "usage: topaz_coarse_gain gain\n");
		exit( 1 );
	}
//	if( gain < 0 || gain > 3 ) {
//		fprintf( stderr, "gain must be in range 0-3\n" );
//		exit( 1);
//	}

	write_Topaz_int( DEF_MCA_PARAM_GAIN_COARSE, gain );
	return 0;
}
