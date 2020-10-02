# Locate the SDK on the BrightSpec jump drive

DIMHWTGZ != echo /media/*/*/SDK/DIMHW/4.0.0/Linux/dimhw-4.0.0.tgz

# Place to install library

LIB = /usr/local/lib

all : sdk lib libusb rules

.PHONY : sdk lib rules libusb

sdk : dimhw-4.0.0

lib : $(LIB)/libdimhw.so 

rules : /etc/udev/rules.d/brightspec.rules

dimhw-4.0.0 : $(DIMHWTGZ)
	tar xvzf $(DIMHWTGZ)
	touch dimhw-4.0.0

$(LIB)/libdimhw.so : dimhw-4.0.0
	cp dimhw-4.0.0/lib/libdimhw-pi.so.4.0.0 $(LIB)/libdimhw.so.4.0.0
	ldconfig
	rm $(LIB)/libdimhw.so
	ln -s $(LIB)/libdimhw.so.4 $(LIB)/libdimhw.so

/etc/udev/rules.d/brightspec.rules :
	echo 'SUBSYSTEM=="usb", ATTR{idVendor}=="04d8", ATTR{idProduct}=="f85d", MODE="0666"' >$@
	udevadm control --reload

libusb :
	apt-get install libusb-1.0

