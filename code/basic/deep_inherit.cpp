///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   deep_inherit.cpp
//  Version     :   0.10
//  Author      :   Jimmy Han
//  Date        :   2014/6/19 15:03
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include "deep_inherit.h"

#include <iostream>
using namespace std;

B1ELEM::B1ELEM()
{
	cout << "B1ELEM::B1ELEM() was called" << endl;
}

B1ELEM::B1ELEM(const B1ELEM &b1)
{
	cout << "B1ELEM copy constructor was called" << endl;
}

B2ELEM::B2ELEM()
{
	cout << "B2ELEM::B2ELEM() was called" << endl;
}

B2ELEM::B2ELEM(const B2ELEM &b2)
{
	cout << "B2ELEM copy constructor was called" << endl;
}

D1ELEM::D1ELEM()
{
	cout << "D1ELEM::D1ELEM() was called" << endl;
}

D1ELEM::D1ELEM(const D1ELEM &d1)
{
	cout << "D1ELEM copy constructor was called" << endl;
}


D2ELEM::D2ELEM()
{
	cout << "D2ELEM::D2ELEM() was called" << endl;
}

D2ELEM::D2ELEM(const D2ELEM &d2)
{
	cout << "D2ELEM copy constructor was called" << endl;
}

D3ELEM::D3ELEM()
{
	cout << "D3ELEM::D3ELEM() was called" << endl;
}

D3ELEM::D3ELEM(const D3ELEM &d3)
{
	cout << "D3ELEM copy constructor was called" << endl;
}

D4ELEM::D4ELEM()
{
	cout << "D4ELEM::D4ELEM() was called" << endl;
}

D4ELEM::D4ELEM(const D4ELEM &d4)
{
	cout << "D4ELEM copy constructor was called" << endl;
}

base1::base1(const B1ELEM &b1, const B2ELEM &b2)
	: base1Elem(b1)
	, base2Elem(b2)
{
	cout << "base1::base1() was called" << endl;
}

derive1::derive1(const B1ELEM &b1, const B2ELEM &b2, const D1ELEM &d1, const D2ELEM &d2)
	: base1(b1, b2)
	, derive1Elem(d1)
	, derive2Elem(d2)
{
	cout << "derive1::derive1() was called" << endl;
}

derive2::derive2(const B1ELEM &b1, const B2ELEM &b2, const D1ELEM &d1, const D2ELEM &d2, const D3ELEM &d3, const D4ELEM &d4)
	: derive1(b1, b2, d1, d2)
	, derive3Elem(d3)
	, derive4Elem(d4)
{
	cout << "derive2::derive2() was called" << endl;
}

void base1::base1Func() {
	cout << "base1Func was called. " << endl;
}


void derive1::derive1Func() {
	cout << "derive1Func was called. " << endl;
}

void derive2::derive2Func() {
	cout << "derive2Func was called. " << endl;
}



