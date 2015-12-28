///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   constructor_test.cc
//  Version     :   0.10	created	2014/05/24 00:00:00		
//  Author      :   Jimmy Han
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include "constructor_test.h"
using namespace std;

B::B(int a)
{
	cout << "B()" << endl;
}

D::D(int b)
	: B(b)
{
	cout << "D()" << endl;
}

int 
main()
{
	D d(1);
	cout << "end" << endl;
	return 0;
}