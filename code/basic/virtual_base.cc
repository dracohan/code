///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   virtual_base.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/11/16 23:18:03
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "virtual_base.h"
using namespace std;

int main(){
	cout << "the size of b1 is: " << sizeof(b1) << endl;
	cout << "the size of d1 is: " << sizeof(d1) << endl;

	cout << "the size of b2 is: " << sizeof(b2) << endl;
	cout << "the size of d2 is: " << sizeof(d2) << endl;

	cout << "the size of b3 is: " << sizeof(b3) << endl;
	cout << "the size of d3 is: " << sizeof(d3) << endl;

	cout << "the size of b4 is: " << sizeof(b4) << endl;
	cout << "the size of d4 is: " << sizeof(d4) << endl;

	d6 d;

	X x;

	return 0;
}