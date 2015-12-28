///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   effect_item33.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/26 16:50:14
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include "effect_item33.h"

#include <iostream>
using namespace std;

void base::
mf1() 
{
	cout << "base::mf1() was called." << endl;
}
void base::
mf1(int) 
{
	cout << "base::mf1(int) was called." << endl;
}
void base::
mf2() 
{
	cout << "base::mf2() was called." << endl;
}
void base::
mf3() 
{
	cout << "base::mf3() was called." << endl;
}
void base::
mf3(double) 
{
	cout << "base::mf3(double) was called." << endl;
}
void derive::
mf1() 
{
	cout << "derive::mf1() was called." << endl;
}
void derive::
mf4() 
{
	cout << "derive::mf4() was called." << endl;
}
