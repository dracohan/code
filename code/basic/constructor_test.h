///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   constructor_test.h
//  Version     :   0.10	created	2014/05/24 00:00:00		
//  Author      :   Jimmy Han
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
/* 
 ** check the relationship between constructor of base class and derived class
 ** 1. when constuctor of derived class is needed?
 ** 2. when constuctor of derived class will called base's constuctor?

 ** answer:
 ** 1. if you want to define the constuct action, or compiler will automatic define a default one.
 ** 2. always. if it's defined, call it, if not, call implicit one. if only defined a non-default constructor, compile error
*/

#include <iostream>

class B {
public:
	// B();
	B(int);
};

class D : public B {
public:
	D(int);
};