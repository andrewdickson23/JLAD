CC = g++
AR = ar
ARFLAGS = -cr 
LIBS = -lcppunit -ldl
THEOBJECTS = user.o ai.o robot.o RandNorm.o RandTest.o Attachment.o
HEADERDIRS = ../../include
OBJDIR = ../../obj/racksdir
CCFLAGS = -I $(HEADERDIRS)
OBJS = $(addprefix $(OBJDIR)/, $(THEOBJECTS))

$(OBJDIR)/%.o : %.cc
	$(CC) $(CCFLAGS) -c -o $@ $<

$(OBJDIR)/librobot.a: $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

racks: $(OBJS) $(OBJDIR)/librobot.a
	$(CC) $(CCFLAGS) -c -o $@ $(OBJS)

.PHONY : clean
clean :
	rm -f $(OBJDIR)/*.o *~ librobot.a
	rm -f *~

## generate the prerequistes and append to the desired file 
.prereq : $(THEOBJECTS:.o=.cc) $(wildcard $(HEADERDIRS)/*.h) Makefile
	rm -f .prereq 
	$(CC) $(CCFLAGS) -MM $(THEOBJECTS:.o=.cc) >> ./.prereq
## include the generated prerequisite file 
include .prereq