///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   c2_vector.cpp
//  Author      :   Jimmy Han
//  Date        :   N.A 			    v1    
//              :   2014/07/13 09:30    v2    
// $ ./a.exe
// Calculate the size of self made Vector class
// sizeof(vint) is: 12

// Self made Vector size test:
// size of vint is: 5
// capacity of vint is: 7
// size of vint2 is: 8
// capacity of vint2 is: 17
// the last element of vint is: 4
// the 5 element of vint is: 4

// Self made iterator test:
// 0 1 2 3

// Iterator called by others:
// [0 1 2 3]
// [0 1 2 3 4 1919249516 1547322171 1735357008]
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "printCollection.h"
#include "c2_vector.h"
using namespace std;
int main()
{
	//default constructor
	Vector<int> vint;
	Vector<int> vint2;
	
	//calc class size, two int, one pointer, so size is 12
	cout << "Calculate the size of self made Vector class " << endl;
	cout <<"sizeof(vint) is: " << sizeof(vint) << endl << endl;
	
	//void push_back(const object &x)
	for (int n=0; n<5; n++)
		vint.push_back(n);
	
	//const Vector& operator=(const Vector &rhs)
	vint2 = vint;
	
	//void resize( int newSize)
	vint2.resize(8);
	
	//int size(); int capacity();
	cout << "Self made Vector size test: " << endl;
	cout << "size of vint is: " << vint.size() << endl;
	cout << "capacity of vint is: " << vint.capacity() << endl;
	cout << "size of vint2 is: " << vint2.size() << endl;
	cout << "capacity of vint2 is: " << vint2.capacity() << endl;
	
	//const object& back();
	cout << "the last element of vint is: " << vint.back() << endl;
	
	//object& operator[](const int index)
	cout << "the 5 element of vint is: " << vint[4] << endl << endl;
	
	//void pop_back()
	vint.pop_back();
	
	//typedef object* iterator; typedef const ojbect* const_iterator
	//iterator begin(); iterator end();
	cout << "Self made iterator test: " << endl;
	for (Vector<int>::iterator iter = vint.begin(); iter != vint.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;
	
	cout << "Iterator called by others: " << endl;
	printCollection(vint); 
	//after resize, not initilized member got random number
	printCollection(vint2); 
}