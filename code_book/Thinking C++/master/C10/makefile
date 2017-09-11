# From "Thinking in C++, 2nd Edition, Volume 2" 
# by Bruce Eckel & Chuck Allison
# Available at http://www.BruceEckel.com
# (c)2003 MindView Inc. Copyright notice in Copyright.txt
# Automatically-generated MAKEFILE 
# For examples in directory .\C10
# Invoke with: make compiler-name
# or: make clean

ifneq ($(MAKECMDGOALS),clean)
include ../$(MAKECMDGOALS).mac
endif

.SUFFIXES : .cpp .$(OBJEXT) .exe
.cpp.$(OBJEXT) :
	$(CPP) $(CPPFLAGS) $(OFLAGS) $<


Borland:  \
	AbstractFactory.exe \
	BeeAndFlowers.exe \
	Bicycle.$(OBJEXT) \
	BuildBicycles.exe \
	CuriousSingleton.exe \
	FunctionStaticSingleton.exe \
	InnerClassIdiom.exe \
	LogFile.$(OBJEXT) \
	ObservedFlower.exe \
	PaperScissorsRock.exe \
	ShapeFactory1.exe \
	ShapeFactory2.exe \
	SingletonPattern.exe \
	SingletonPattern2.exe \
	UseLog1.$(OBJEXT) \
	UseLog2.exe \
	VirtualConstructor.exe

Microsoft:  \
	AbstractFactory.exe \
	BeeAndFlowers.exe \
	Bicycle.$(OBJEXT) \
	BuildBicycles.exe \
	CuriousSingleton.exe \
	FunctionStaticSingleton.exe \
	InnerClassIdiom.exe \
	LogFile.$(OBJEXT) \
	ObservedFlower.exe \
	PaperScissorsRock.exe \
	ShapeFactory1.exe \
	ShapeFactory2.exe \
	SingletonPattern.exe \
	SingletonPattern2.exe \
	UseLog1.$(OBJEXT) \
	UseLog2.exe \
	VirtualConstructor.exe

g++:  \
	AbstractFactory.exe \
	BeeAndFlowers.exe \
	Bicycle.$(OBJEXT) \
	BuildBicycles.exe \
	CuriousSingleton.exe \
	FunctionStaticSingleton.exe \
	InnerClassIdiom.exe \
	LogFile.$(OBJEXT) \
	ObservedFlower.exe \
	PaperScissorsRock.exe \
	ShapeFactory1.exe \
	ShapeFactory2.exe \
	SingletonPattern.exe \
	SingletonPattern2.exe \
	UseLog1.$(OBJEXT) \
	UseLog2.exe \
	VirtualConstructor.exe

edg:  \
	AbstractFactory.exe \
	BeeAndFlowers.exe \
	Bicycle.$(OBJEXT) \
	BuildBicycles.exe \
	CuriousSingleton.exe \
	FunctionStaticSingleton.exe \
	InnerClassIdiom.exe \
	LogFile.$(OBJEXT) \
	ObservedFlower.exe \
	PaperScissorsRock.exe \
	ShapeFactory1.exe \
	ShapeFactory2.exe \
	SingletonPattern.exe \
	SingletonPattern2.exe \
	UseLog1.$(OBJEXT) \
	UseLog2.exe \
	VirtualConstructor.exe

Metrowerks:  \
	AbstractFactory.exe \
	BeeAndFlowers.exe \
	Bicycle.$(OBJEXT) \
	BuildBicycles.exe \
	CuriousSingleton.exe \
	FunctionStaticSingleton.exe \
	InnerClassIdiom.exe \
	LogFile.$(OBJEXT) \
	ObservedFlower.exe \
	PaperScissorsRock.exe \
	ShapeFactory1.exe \
	ShapeFactory2.exe \
	SingletonPattern.exe \
	SingletonPattern2.exe \
	UseLog1.$(OBJEXT) \
	UseLog2.exe \
	VirtualConstructor.exe

clean:
ifeq ($(notdir $(SHELL)),COMMAND.COM)
	del *.obj
	del *.exe
	del *.tds
	del *.o
else
	rm -f *.o *.obj *.exe *.tds
endif


AbstractFactory.exe: AbstractFactory.cpp


BeeAndFlowers.exe: BeeAndFlowers.cpp


Bicycle.$(OBJEXT): Bicycle.cpp


BuildBicycles.exe: Bicycle.$(OBJEXT) BuildBicycles.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)BuildBicycles.exe BuildBicycles.$(OBJEXT) Bicycle.$(OBJEXT)

BuildBicycles.$(OBJEXT): BuildBicycles.cpp

CuriousSingleton.exe: CuriousSingleton.cpp


FunctionStaticSingleton.exe: FunctionStaticSingleton.cpp


InnerClassIdiom.exe: InnerClassIdiom.cpp


LogFile.$(OBJEXT): LogFile.cpp


ObservedFlower.exe: ObservedFlower.cpp


PaperScissorsRock.exe: PaperScissorsRock.cpp


ShapeFactory1.exe: ShapeFactory1.cpp


ShapeFactory2.exe: ShapeFactory2.cpp


SingletonPattern.exe: SingletonPattern.cpp


SingletonPattern2.exe: SingletonPattern2.cpp


UseLog1.$(OBJEXT): UseLog1.cpp


UseLog2.exe: LogFile.$(OBJEXT) UseLog1.$(OBJEXT) UseLog2.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)UseLog2.exe UseLog2.$(OBJEXT) LogFile.$(OBJEXT) UseLog1.$(OBJEXT)

UseLog2.$(OBJEXT): UseLog2.cpp

VirtualConstructor.exe: VirtualConstructor.cpp


