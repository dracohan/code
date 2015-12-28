///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   use_private_inherit_judiciously_item39.h.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/23 16:52:45
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////

#include "use_private_inherit_judiciously_item39.h"
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
