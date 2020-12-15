#include "twrap.h"

int main( int argc, char *argv[] ) {
	
	int p = read_Topaz_int( DEF_MCA_PARAM_GAIN_DIGITAL );
	printf( "Digital gain: %d (%d)\n", p, 1<<p );
	p = read_Topaz_int( DEF_MCA_PARAM_GAIN_COARSE );
	printf( "Coarse gain: %d (%d)\n", p, 1<<p );
	p = read_Topaz_int( DEF_MCA_PARAM_GAIN_FINE );
	printf( "Fine gain: %d (%f)\n", p, (p + 4096)/4096.0 );
	p = read_Topaz_int( DEF_MCA_PARAM_THRESHOLD );
	printf( "Threshold: %d\n", p );
	p = read_Topaz_int( DEF_MCA_PARAM_ADC_SAMPLING_RATE );
	double fs = p/1000000.0;	// MHz
	printf( "ADC sample rate: %d (%f MHz)\n", p, fs );
	p = read_Topaz_int( DEF_MCA_PARAM_RISE_TIME );
	printf( "Rise time: %d (%f us)\n", p, p/fs );
	p = read_Topaz_int( DEF_MCA_PARAM_FLAT_TOP );	
	printf( "Flat top: %d (%f us)\n", p, p/fs );
	return 0;
}
