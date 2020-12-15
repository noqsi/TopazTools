#include "twrap.h"

int main( int argc, char *argv[] ) {
	
	int threshold;
	if( argc != 2 || sscanf( argv[1], "%d", &threshold ) != 1 ) {
		fprintf( stderr, "usage: topaz_threshold threshold\n");
		exit( 1 );
	}
	if( threshold < 0 || threshold > 4095 ) {
		fprintf( stderr, "threshold must be in range 0-4095\n" );
		exit( 1);
	}

	write_Topaz_int( DEF_MCA_PARAM_THRESHOLD, threshold );
	return 0;
}
