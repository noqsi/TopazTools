# TopazTools
Tools for use of the Topaz multichannel analyzer.

## Tools

### qdaq

Acquires spectrum and external counts for five second integrations from a connected Topaz MCA. It's intended for bench testing and logging background data.

The output is a tab-separated value (TSV) stream to standard output. Typical usage is:

    qdaq | tee output.tsv

The `qdaq` command does not take arguments.

## Installation on Raspberry Pi

### Setup
These instructions assume you have a BrightSpec USB drive containing version 4.0.0 of the DIMHW tools automounted on a Raspberry Pi. They've been tested on a Rasperry Pi 3B running Raspbian Buster. A similar procedure predating the Makefile succeeded on a Model 2B.

In the `TopazTools` directory:

    sudo make

This extracts the BrightSpec Linux development tree into a directory in `TopazTools`. It installs the runtime library in `/usr/local/lib`. It sets up user access to the MCA over USB, and insures that the Linux libusb is installed.

### Tools
    cd src
    make

This builds `qdaq`.