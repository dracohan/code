///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   meffect_item27.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/11/27
//  Comment     :	
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "meffect_item27.h"

B::~B()
{
	cout << "B::~B() was called." << endl;
}
int main(){
	//private ~B() failed this
	//B b;

	//B was only allowed to allocate on heap, not stack
	B* pb = new B();
	//delete pb was forbidden because ~B() was private
	pb->destroy();

	D* pd = new D();
	pd->destroy();

	//can't delete pe because ~B() will be called by it
	E* pe = new E();
	delete pe;

	return 0;
}