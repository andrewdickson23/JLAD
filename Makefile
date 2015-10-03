# Makefile for the J-LAD SCI - RACKS program.
# Written by James Palawaga
# November 12, 2012

# Make all
.PHONY : all
all: clean src testcases

# Make production code
.PHONY : src
	$(MAKE) -C src

# Make test program
.PHONY : testcases
testcases:
	$(MAKE) -C src
	$(MAKE) -C test

# Cleanup unused files
clean:
	$(MAKE) -C src clean
	$(MAKE) -C test clean