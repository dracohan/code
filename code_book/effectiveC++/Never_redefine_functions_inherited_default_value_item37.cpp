///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   Never_redefine_functions_inherited_default_value_item34.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/23 14:41:00
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////

#include "Never_redefine_functions_inherited_default_value_item34.h"
#include <iostream>
using namespace std;

const char* colorBox[]
{
	"RED", "GREEN", "BLUE"
};

void
Shape::draw(ShapeColor color) const
{
	cout << "Shape::draw() with default value " << colorBox[color] << endl;
}

void
Rectangel::draw(ShapeColor color) const
{
	cout << "Rectangel::draw() with default value " << colorBox[color] << endl;
}

	
	
