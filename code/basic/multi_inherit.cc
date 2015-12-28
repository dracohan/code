///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   multi_inherit.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/26 16:50:14
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include "multi_inherit.h"

#include <iostream>
using namespace std;

void base1::baseFunc() {
	cout << "base1Func was called. " << endl;
}

void base2::baseFunc() {
	cout << "base2Func was called. " << endl;
}

void derive1::derive1Func() {
	cout << "derive1Func was called. " << endl;
}

void derive2::derive2Func() {
	cout << "derive2Func was called. " << endl;
}

void derive2::baseFunc() {
	base2::baseFunc();
}



