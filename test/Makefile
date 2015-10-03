# Variables
HEADDIR = ../include
LIBDIR = ../obj/racksdir
OBJS = mainTest.o
LIBS = -lcppunit -ldl -lrobot -ltile
TRGT = gameTester
CC = g++
CCFLAGS = -g -Wall -I $(HEADDIR)
LNFLAGS = -L$(LIBDIR)/

#link gameTester with it's .o files and with the library we've created
$(TRGT): $(OBJS) $(LIBDIR)/libtile.a $(LIBDIR)/librobot.a
	$(CC) $(LNFLAGS) -o $@ $(OBJS) $(LIBS)

%.o : %.cc
	$(CC) $(CCFLAGS) -c -o $@ $< 

.DependencyList: $(OBJNAMES:.o=.cc) $(wildcard $(HEADDIR)/*.h) $(wildcard *h)  Makefile
	rm -f .DependencyList
	$(CC) $(CCFLAGS) -MM $(OBJS:.o=.cc)  >> ./.DependencyList
include .DependencyList


.PHONY : clean      
clean:
	rm -f *.o *~

.PHONY: clean-all
clean-all: clean
	rm -f $(TRGT)