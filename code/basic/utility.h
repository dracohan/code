///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   utility.h
//  Version     :   0.10	created	2014/05/24 00:00:00		
//  Author      :   Jimmy Han
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

template <typename T>
void PRINT_ELEMENT(const T& container, const char* optcstr="content:")
{
	typename T::const_iterator pos;
	std::cout << optcstr << endl;
	for(pos = container.begin(); pos != container.end(); ++pos)
		cout << *pos << ' ';
	std::cout << std::endl;
}

template <typename T>
void INSERT_ELEMENT(T& container, int first, int last)
{
	for(int i = first; i <= last; ++i)
		container.insert(container.end(), i);
}

inline void PrintVal(const string &cstr)
{
	cout << "The value of str is:" << cstr << endl;
}
