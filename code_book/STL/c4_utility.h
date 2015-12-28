///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   c4_utility.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/26 16:50:14
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#ifndef C4_UTILITY_H
#define	C4_UTILITY_H

#include<utility>
using namespace std;


//pair definition
pair<int, float> p;
pair<int, const char*> p(42, "Hello");


//make_pair could be used to replace pair<int, fload>
//implicit conversion is also supported
void f(pair<int, const char*>);
void g(pair<const int, string>);

f(make_pair<42,"Hello">);
g(make_pair<42,"Hello">);

//legacy pointer is NOT good
void f()
{
	classA* ptr = new classA;
	try {
		...
	}
	catch(...)
	{
		delete ptr;
		throw;	
	}
	delete ptr;
}
//auto_ptr should be used
#include<memory> //auto_ptr header
void f()
{
	auto_ptr<classA> ptr(new classA);
}

//auto_ptr should be initialized directly 
//instead of assigned 
auto_ptr<classA> ptr1(new classA); //OK
auto_ptr<classA> ptr2 = new classA; //NOK
ptr1 = auto_ptr<classA>(new int(42)); //OK
ptr1 = new int 42; //NOK

//whenever an object is transferred via an auto_ptr
//use constant auto_ptr to signal the end of the chain	
//const auto_ptr<int> is equal to int* const p
//its value can be changed, but can't point to other object

//deconstructor are only be called for object that have been fully constructed




#endif