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
using namespace std;

int main()
{
	//Shape* pShape = new Rectangel;
	//pShape->draw();
	string s1("Nancy");
	string s2("Clany");
	
	string& rs = s1;
	string* ps = &s2;
	
	rs = s2;
	
	cout << "rs: " << rs << endl;
	cout << "ps: " << *ps << endl;
	
	return 0;	
}
