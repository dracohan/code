///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   point_reference_item1_client.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/08/21 16:32:00
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
  
#include "point_reference_item1.h"
#include <iostream>
//for operator new/delete
//#include <new>

//for auto_ptr
#include <memory>

using namespace std;

int main()
{
	//new
	Shape* pshape = new Rectangel;

	//delete
	delete pshape;

	//operator new
	void* rawMemory = operator new(sizeof(Rectangel));

	//operator delete
	operator delete(rawMemory);

	//item9
	//auto_prt, shared_ptr
	auto_ptr<Shape> pp(new Rectangel);
	//std::tr1::shared_ptr<Shape> ppp(new Rectangel);

	return 0;	
}
