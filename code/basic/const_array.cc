///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   const_array.cc
//  Version     :   0.10	created	2014/05/10 16:00:00	
//  Author      :   Jimmy Han
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include "const_array.h"
#include <iostream>

const int Base::_ciaa[10] = {0,1,2,3,4,5,6,7,8,9};

void
Base::get()
{
	cout << "the value of _cia is: " << _cia << endl;
	cout << "the value of _ciaa is: " << endl;
	for(int i = 0; i < 10 ; i++)
		cout << _ciaa[i] << endl;
}