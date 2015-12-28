///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   no_virtual_func_in_stor_item09.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/s 16:51:03
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////

#include "no_virtual_func_in_stor_item09.h"
#include <iostream>
using namespace std;

Shape::Shape()
{
	LogTransation();
}

void
Shape::LogTransation() 
{
	cout << "Shape::LogTransation()" << endl;
}

Rectangel::Rectangel()
{
	LogTransation();
}

void
Rectangel::LogTransation() 
{
	cout << "Rectangel::LogTransation()" << endl;
}

	
	
