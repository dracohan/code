///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   meffect_item5.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/11/18
//  Comment     :  prefix and postfix
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "meffect_item5.h"
using namespace std;

ostream& operator<<(ostream &os, const A&a)
{
	return os<<a.value;
}
int main(){
	int i = 5;

	//postfix return a const value
	//i++++;
	
	//prefix return a reference
	++++i;

	A a(0,10);
	cout << a++ << endl;
	cout << ++a << endl;
	A b(0,10);
	cout << b.operator++(9) << endl;
	cout << b.operator++() << endl;

	return 0;
}