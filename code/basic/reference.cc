///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   reference.cpp
//  Version     :   0.10	created	2014/05/10 18:58		
//  Author      :   Jimmy Han
//  Comment     :	reference usage
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

void 
foo(int &i)
{
	i++;
}

int 
main()
{
	//normal reference
	int 	ival = 1024;
	int& 	rval = ival;

	//reference to a pointer
	int*	pi 	 = &ival;
	int*	&piv = pi;
	//NOK, reference can't be initialized by a address
	//int*	&piv = &ival;

	//pass argument via reference
	rval 	= 999;
	foo(rval);

	//trip, rval not reference to min, but still reference to ival
	int 	min = 0;
	rval = min;
	rval += 2;

	//reference to a const object
	const int abc = 2048;
	//const int* pabc = &abc;
	const int* const &prabc = &abc;

	cout << "The value of min is: " << min << endl;
	cout << "The value of ival is: " << ival << endl;
	

}