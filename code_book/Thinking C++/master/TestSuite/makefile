# From "Thinking in C++, 2nd Edition, Volume 2" 
# by Bruce Eckel & Chuck Allison
# Available at http://www.BruceEckel.com
# (c)2003 MindView Inc. Copyright notice in Copyright.txt
# Automatically-generated MAKEFILE 
# For examples in directory .\TestSuite
# Invoke with: make compiler-name
# or: make clean

ifneq ($(MAKECMDGOALS),clean)
include ../$(MAKECMDGOALS).mac
endif

.SUFFIXES : .cpp .$(OBJEXT) .exe
.cpp.$(OBJEXT) :
	$(CPP) $(CPPFLAGS) $(OFLAGS) $<


Borland:  \
	Suite.$(OBJEXT) \
	Test.$(OBJEXT)

Microsoft:  \
	Suite.$(OBJEXT) \
	Test.$(OBJEXT)

g++:  \
	Suite.$(OBJEXT) \
	Test.$(OBJEXT)

edg:  \
	Suite.$(OBJEXT) \
	Test.$(OBJEXT)

Metrowerks:  \
	Suite.$(OBJEXT) \
	Test.$(OBJEXT)

clean:
ifeq ($(notdir $(SHELL)),COMMAND.COM)
	del *.obj
	del *.exe
	del *.tds
	del *.o
else
	rm -f *.o *.obj *.exe *.tds
endif


Suite.$(OBJEXT): Suite.cpp


Test.$(OBJEXT): Test.cpp


