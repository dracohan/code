///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   inherite.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/24 09:43:15
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////

#include "inherite.h"
#include <iostream>
using namespace std;

//Base Class
Base::Base() : public_val(1), protected_val(2), private_val(3)
{
	cout << "Base ctr() was called." << endl;	
}

Base::~Base() 
{
	cout << "Base dtr() was called." << endl;	
}

void Base::public_func()
{
	cout << "Base public_func() was called." << endl;
	//类构建者可以访问自己的所有函数和成员变量
	//protected_func();
	//private_func();
	//cout << "public_val is: " << public_val << endl;
	//cout << "protected_val is: " << protected_val << endl;
	//cout << "private_val is: " << private_val << endl;
}

void Base::public_virtual_func_caller()
{
	cout << "Base public_virtual_func_caller() was called." << endl;
	public_virtual_func();
}

void Base::public_virtual_func()
{
	cout << "Base public_virtual_func() was called." << endl;
}

void Base::protected_func()
{
	cout << "Base protected_func() was called." << endl;
}

void Base::protected_virtual_func()
{
	cout << "Base protected_virtual_func() was called." << endl;
}

void Base::private_func()
{
	cout << "Base private_func() was called." << endl;
}

void Base::private_virtual_func()
{
	cout << "Base private_virtual_func() was called." << endl;
}

//Derived Class
void Derived::public_func()
{
	cout << "Derived public_func() was called." << endl;
}

void Derived::public_func_caller()
{
	cout << "Derived public_func_caller() was called." << endl;
	//派生类可以访问基类public函数与变量
	Base::public_func();
	cout << "public_val is: " << public_val << endl;
	//派生类可以访问基类protected函数与变量
	Base::protected_func();
	cout << "protected_val is: " << protected_val << endl;
	//派生类可以访问基类private函数与变量
	//Base::private_func();
	//cout << "private_val is: " << private_val << endl;
}

void Derived::public_virtual_func()
{
	cout << "Derived public_virtual_func() was called." << endl;
}



void Derived::private_virtual_func()
{
	cout << "Derived private_virtual_func() was called." << endl;
}
/*
//Derived2 Class
void Derived2::public_virtual_func()
{
	cout << "Derived2 public_virtual_func() was called." << endl;
}
*/


//Derived3 Class
void Derived3::public_virtual_func()
{
	//private继承
	cout << "Derived3 public_virtual_func() was called." << endl;
	//同public继承一样，public和protected可以访问，private不能
	Base::public_func();
	cout << "public_val is: " << public_val << endl;
	Base::protected_func();
	cout << "protected_val is: " << Base::protected_val << endl;
	//Base::private_func();
	//cout << "private_val is: " << private_val << endl;
}

