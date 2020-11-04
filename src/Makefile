CFLAGS = -g -Wall -I../dimhw-4.0.0/include/ -DHV_LIMIT=$(HV_LIMIT)
LDFLAGS = -ldimhw -lusb-1.0
BINARIES = qdaq topaz_hv topaz_hv_off

# Compiled-in HV voltage limit.
# 70V is suitable for PIPS detectors.

HV_LIMIT = 70.0

.PHONY : all install

all : $(BINARIES)

install : $(BINARIES)
	cp -a $(BINARIES) /usr/local/bin/

clean:
	rm -f *.o $(BINARIES)
