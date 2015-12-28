///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   meffect_item26.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/11/25
//  Comment     :	limit object number to 1
//
///////////////////////////////////////////////////////////////////////////////
#ifndef MEFFECT_ITEM26_H
#define	MEFFECT_ITEM26_H
#include <iostream>
using namespace std;

//restrict class object to 0/1
namespace PrintingStuff {

	class Printer{
		public:
			friend Printer& thePrinter();
		private:
			//avoid construct
			Printer();
			Printer(const Printer&);
	};

	Printer::Printer()
	{
		cout << "Printer::Printer() was called" << endl;
	}

	//should not use inline here
	//because inline will lead to multi copy of functions
	//while static indicate only one copy
	//so don't inline functions has local static object
	//refer to more effective c++ page 101
	Printer& thePrinter(){
		static Printer p;
		return p;
	}
}

//restrict class object to 1/more
//private constructor+psuedo-constructor
template<class BeingCounted>
class Counted{
public:
	static size_t objectCount(){return numobject;}
protected:
	//protected to allow inherited class to call it, in other word, make Counted could be derived by other classes
	Counted(){
		if(numobject >= maxobject)
			cout << "number exceed." << endl;
		else
		{
			++numobject;cout << "Counted();" << endl;
		}
	}
	Counted(const Counted& rhs){
		if(numobject >= maxobject)
			cout << "number exceed." << endl;
		else
		{
			++numobject;
			cout << "Counted(const Counted& rhs);" << endl;
		}
	}
		
	~Counted(){--numobject;}
private:
	static size_t numobject;
	static const size_t maxobject;
};

//initializd numobject to zero
template<class BeingCounted>
size_t Counted<BeingCounted>::numobject;
	
class Scanner : private Counted<Scanner> {
//private derive means it's implementation inherit
//Counter* pt = new Scanner is forbidden
//if not, virtual de-constructor should be provided, this will increase the burden of derive from Counted class.
public:
	using Counted<Scanner>::objectCount;
	static Scanner* makeScanner(){
			return new Scanner();
	}
	static Scanner* makeScanner(const Scanner& rhs){
			return new Scanner(rhs);
	}

private:
	//private to avoid:
	//1: being derived
	//2: being embeded into other classes
	Scanner(){cout << "Scanner() was called." << endl;}
	Scanner(const Scanner& rhs){cout << "Scanner(const Scanner& rhs) was called." << endl;}
};

template<>
const size_t Counted<Scanner>::maxobject = 2;

#endif