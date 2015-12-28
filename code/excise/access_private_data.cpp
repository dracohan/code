///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   access_private_data.cpp
//  Version     :   0.10
//  Author      :   Jimmy Han
//  Date        :   2015/05/17 16:50:14
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include "access_private_data.h"
#include <iostream>
using namespace std;

data::data(int a[5])
{
	cout << "data::data(int[] a)" << endl;
	//cout << "sizeof(a): "<< sizeof(a) << endl;
	for(int i = 0; a[i] != NULL ; i++)
		_data[i] = a[i];
}

void 
data::printdata()
{
	cout << "data::printdata()" << endl;
	cout << "sizeof(_data): " <<sizeof(_data) << endl;
	for(int i = 0; i < sizeof(_data)/sizeof(_data[0]); i++)
		cout << _data[i] << " ";
}