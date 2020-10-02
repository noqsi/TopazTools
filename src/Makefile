CFLAGS = -g -Wall -I../dimhw-4.0.0/include/
LDFLAGS = -ldimhw -lusb-1.0

.PHONY : all install

all : qdaq

install : qdaq
	cp -a qdaq /usr/local/bin/

clean:
	rm -f *.o qdaq
