///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   Never_redefine_functions_inherited_default_value_item34_client.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/23 14:40:30
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
  
#include "Never_redefine_functions_inherited_default_value_item34.h"
#include <iostream>
using namespace std;

int main()
{
	Shape* pShape = new Rectangel;
	pShape->draw();
	
	Rectangel* prect = new Rectangel;
	prect->draw();
	
	return 0;	
}
