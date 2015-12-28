///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   effect_item9.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/11/01 16:01:03
//  Comment     :  
//$ ./a
//	~D() was called.
//	~B() was called.
//	pure virtual method called
//	terminate called without an active exception
//	Aborted (core dumped)
///////////////////////////////////////////////////////////////////////////////
#include "effect_item9.h"
#include <iostream>

using namespace std;


void D::
pureVirtual(){
		cout << "D::pureVirtual() was called. " << endl;
		cout << endl;
}

	
int main()
{
	//B* pb = new B;
	D d;
    
    return 0;
}

