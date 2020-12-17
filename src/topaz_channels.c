#include "twrap.h"

int main( int argc, char *argv[] ) {
	
	int chan;
	if( argc != 2 || sscanf( argv[1], "%d", &chan ) != 1 ) {
		fprintf( stderr, "usage: topaz_channels number\n");
		exit( 1 );
	}

	write_Topaz_int( DEF_MCA_PARAM_NUM_CHANNELS, chan );
	return 0;
}
