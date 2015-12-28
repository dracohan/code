///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   point_reference_item1.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/08/21 16:32:00
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////

#include "point_reference_item1.h"
#include <iostream>
using namespace std;

void
Shape::draw(ShapeColor color) const
{
	cout << "Shape::draw" << color << endl;
}

void
Rectangel::draw(ShapeColor color) const
{
	cout << "Rectangel::draw" << color << endl;
}

	
	
