#ifndef TWRAP_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include "DIMHW.h"

int32_t read_Topaz_int( int32_t paramid );
void write_Topaz_int( int32_t paramid, int32_t p );
const char *Topaz_name( void );
const char *Topaz_serial( void );

#define TWRAP_H
#endif
