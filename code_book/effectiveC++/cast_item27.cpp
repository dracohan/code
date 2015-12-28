///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   cast_item27.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/10/31 15:43:55
//  Comment     :  
//	
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

int main() {
	//static_cast
	int a = 4;
	a = 5;
	const int b = static_cast<const int>(a);
	cout << "b is: " << b << endl;
	
	//dynamic_cast
	//see D:\cygwin\home\baoweih\code_book\c++ primer\p838_dynamiccast.h
	
	//reinterpret_cast
	char* k = reinterpret_cast<char*>(b);
		
	//const_cast
	//http://www.cnblogs.com/dracohan/p/3417842.html
	const int* i = &b;
	//compile error, invalid conversion from ¡®const int*¡¯ to ¡®int*¡¯
	//int* j = i;
	int* j = const_cast<int*>(i);
	//successfully change a const value
	*j = 6;
	cout << "b is: " << b << endl;
	
	//reference
	const int& l = b;
	int& m = const_cast<int&>(l);
	//error: assignment of read-only reference ¡®l¡¯
	//l = 7;
	//successfully change a const reference
	m = 7;
	cout << "b is: " << b << endl;

	//const point
	const int* const pint = new int(1024);
	// can't change *pint
	//*pint = 1023;
	// cant' change pint also
	//pint = new int(1023);
	int* const fake_pint = const_cast<int* const>(pint);
	// can change *pint now
	*fake_pint = 1023;
	// still cant' change pint also
	//fake_pint = new int(1023);



	cout << "*fake_pint is: " << *fake_pint << endl;
	
		
	return 0;
}
