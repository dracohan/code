///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   effect_item34_client.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/23 14:40:30
//  Comment     :  
//
//	Derive::draw() with default value RED
//	Base::pureFunc() was called.
//	Base::virtualFunc() was called.
//	Derive::draw() with default value GREEN
//	Base::virtualFunc2() was called.
//	Derive::virtualFunc2() was called.
///////////////////////////////////////////////////////////////////////////////
  
#include "effect_item34.h"
#include <iostream>
using namespace std;

int main()
{
	Base* pShape = new Derive;
	pShape->draw();
	pShape->pureFunc();
	pShape->virtualFunc();
	
	Derive* prect = new Derive;
	prect->draw();
	prect->virtualFunc2Wrapper();
	
	return 0;	
}
