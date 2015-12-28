///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   size_of.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/10/31 14:15:30
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////

#include "size_of.h"
#include <iostream>
#include <cstring>
using namespace std;

int main () 
{
	//sizeof
	//array
	//pointer
	//funtion
	//types
	//object
	int intArray[10];
	int* pi = new int(4);
	short f();
	string str("abcdefg");

	cout << "sizeof int is: " << sizeof(int) << endl;
	cout << "sizeof float is: " << sizeof(float) << endl;
	cout << "sizeof char is: " << sizeof(char) << endl;
	cout << "sizeof long is: " << sizeof(long) << endl;
	cout << "sizeof unsigned int is: " << sizeof(unsigned int) << endl;
	cout << "sizeof double is: " << sizeof(double) << endl;
	
	cout << "sizeof intArray is: " << sizeof(intArray) << endl;
	cout << "sizeof int* is: " << sizeof(pi) << endl;
	cout << "sizeof f() is: " << sizeof(f()) << endl;
	cout << "sizeof str is: " << sizeof(str) << endl;
	cout << "Sizeof an empty class is: " << sizeof(Empty) << endl;
	cout << "Sizeof an HoldAnInt class is: " << sizeof(HoldAnInt) << endl;
	cout << "Sizeof an NonVirtual Derived class is: " << sizeof(NonVirtualDerived) << endl;
	cout << "Sizeof an Virtual Derived class is: " << sizeof(VirtualDerived) << endl;
	
	//strlen
	//char*
	char charArray[10] = "abcd";
	char* charPoint = "01235";
	cout << "strlen charArray is: " << strlen(charArray) << endl;
	cout << "strlen charPoint is: " << strlen(charPoint) << endl;

	delete pi;
}

