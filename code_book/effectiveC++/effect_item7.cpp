///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   effect_item7.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/11/14 13:17
//  Comment     :  
//	$ ./a
//	size of B is: 1
//	DD pureVirtualFunc() was called
//	AA::~AA() was called
//	A::~A() was called
//	B deconstructor was called
//	
///////////////////////////////////////////////////////////////////////////////

#include "effect_item7.h"
#include <iostream>

using namespace std;

//DD has to implement void pureVirtualFunc() to be concrete
void DD::
pureVirtualFunc(){
		cout << "DD pureVirtualFunc() was called" << endl;
		}

void AA::
	VirtualFunc(){
			cout << "AA::VirtualFunc() was called" << endl;
		}

int main()
{
    cout << "size of B is: " << sizeof(B) << endl;
    
    DD d;
    d.pureVirtualFunc();
    
    //AA member _size won't be deconstructed
    A* pA = new AA();
    delete pA;
    
    return 0;
}

