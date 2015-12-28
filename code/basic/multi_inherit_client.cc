///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   multi_inherit_client.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/26 16:50:14
//  Comment     :  
//	Output		:
//	$ ./a
// $ ./a.exe
// base2Func was called.
// derive1Func was called.
// derive2Func was called.
// base1Func was called.
// derive1Func was called.

///////////////////////////////////////////////////////////////////////////////
#include "multi_inherit.h"
#include <iostream>
using namespace std;

int main() {
	derive2 d2;
	//if not embed, this will be ambigous and compile error
	d2.baseFunc();
	//could call both derive1Func and derive2Func
	d2.derive1Func();
	d2.derive2Func();
	
	derive1* b1 = new derive2;
	//call base1 or derive1 functions, OK
	b1->baseFunc();
	b1->derive1Func();
	//call base2 or derive2 functions, compile error.
	//b1->derive2Func();
	
	return 0;
}



	


