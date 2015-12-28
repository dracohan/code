///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   effect_item34.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/23 14:41:00
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////

#include "effect_item34.h"
#include <iostream>
using namespace std;

const char* colorBox[]
{
	"RED", "GREEN", "BLUE"
};

void
Base::draw(ShapeColor color) const
{
	cout << "Base::draw() with default value " << colorBox[color] << endl;
}

void
Base::pureFunc()
{
	cout << "Base::pureFunc() was called. " << endl;
}

void
Base::virtualFunc()
{
	cout << "Base::virtualFunc() was called. " << endl;
}

void
Base::nonvirtualFunc()
{
	cout << "Base::nonvirtualFunc() was called. " << endl;
}

void
Base::virtualFunc2Wrapper()
{
	virtualFunc2();
}

void
Base::virtualFunc2()
{
	cout << "Base::virtualFunc2() was called. " << endl;
}

void
Derive::virtualFunc2()
{
	Base::virtualFunc2();
	cout << "Derive::virtualFunc2() was called. " << endl;
}

void
Derive::pureFunc()
{
	//inherit base default function, only if write it here, or it will not get base function.
	Base::pureFunc();
}

void
Derive::draw(ShapeColor color) const
{
	cout << "Derive::draw() with default value " << colorBox[color] << endl;
}

	
	
