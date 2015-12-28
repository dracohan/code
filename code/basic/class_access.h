///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   class_access.h
//  Version     :   0.10	created	2014/05/00 00:00:00		
//  Author      :   Jimmy Han
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

class B {
	float b;
};

class A {
	int a;
	void assign(A& another) {
		a = another.a;
	}
};


