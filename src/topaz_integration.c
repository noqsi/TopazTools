#include "twrap.h"

int main( int argc, char *argv[] ) {
	
	float t;
	if( argc != 2 || sscanf( argv[1], "%f", &t ) != 1 ) {
		fprintf( stderr, "usage: topaz_integration time_in_seconds\n");
		exit( 1 );
	}

	write_Topaz_float( DEF_MCA_PARAM_PRESET_TIME, t );
	return 0;
}
