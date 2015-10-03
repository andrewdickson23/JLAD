CC = g++
AR = ar
ARFLAGS = -cr 
LIBS = -lcppunit -ldl
THEOBJECTS = ConcreteBoard.o ConcreteTile.o
HEADERDIRS = ../../include
OBJDIR = ../../obj/racksdir
CCFLAGS = -I $(HEADERDIRS)
OBJS = $(addprefix $(OBJDIR)/, $(THEOBJECTS))

$(OBJDIR)/libtile.a: $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

racks: $(OBJS) $(OBJDIR)/libtile.a
	$(CC) $(CCFLAGS) -c -o $@ $(OBJS)

$(OBJDIR)/%.o : %.cc
	$(CC) $(CCFLAGS) -c -o $@ $<

.PHONY : clean
clean :
	rm -f $(OBJDIR)/*.o *~ libtile.a
	rm -f *~

## generate the prerequistes and append to the desired file 
.prereq : $(THEOBJECTS:.o=.cc) $(wildcard $(HEADERDIRS)/*.h) Makefile
	rm -f .prereq 
	$(CC) $(CCFLAGS) -MM $(THEOBJECTS:.o=.cc) >> ./.prereq
## include the generated prerequisite file 
include .prereq