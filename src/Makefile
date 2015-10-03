# Makefile as developed in-class 2720
# Adjusted for use for the J-LAD CSI - RACKS program by James Palawaga on
# November 12, 2012

CC = g++
THEOBJECTS = 
LIBDIR = ../obj/racksdir
HEADERDIRS = ../include
OBJDIR = ../obj
TRGT = ../obj/RACKS
OBJS = main.o utility.o 
CCFLAGS = -g -Wall -I $(HEADERDIRS)
LNFLAGS = -L$(LIBDIR)
LIBS = ../obj/racksdir/libtile.a ../obj/racksdir/librobot.a

.PHONY: all
all:
	$(MAKE) -C robot
	$(MAKE) -C tile_board
	$(MAKE) $(TRGT)

# generate the production code by linking here ...
$(TRGT) : $(OBJS)
	$(CC) $(LNFLAGS) -o $@ $^ $(LIBS)

%.o : %.cc
	$(CC) $(CCFLAGS) -c -o $@ $<

.PHONY : clean
clean :
	rm -f $(OBJDIR)/*.o *~
	rm -f *.o *~
	$(MAKE) -C tile_board clean
	$(MAKE) -C robot clean

## generate the prerequistes and append to the desired file 
.prereq : $(OBJS:.o=.cc) $(wildcard $(HEADERDIRS)/*.h) Makefile
	rm -f .prereq 
	$(CC) $(CCFLAGS) -MM $(OBJS:.o=.cc) >> ./.prereq
# include the generated prerequisite file 
include .prereq