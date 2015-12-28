///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   meffect_item5.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/11/18
//  Comment     :  prefix and postfix
//
///////////////////////////////////////////////////////////////////////////////
#ifndef MEFFECT_ITEM5_H
#define	MEFFECT_ITEM5_H
#include <iostream>
using namespace std;

class A{
	friend ostream& operator <<(ostream &os, const A &a);
public:
	A(int initvalue=0, int initstep=1):value(initvalue), step(initstep){}

	//prefix
	A& operator++(){
		cout << "A& operator++() was called" << endl;
		value+=step;
		return *this;
	}

	//postfix
	const A operator++(int){
		cout << "const A operator++(int) was called." << endl;
		const A oldA = *this;
		++(*this);
		return oldA;
	}
private:
	int value;
	int step;
};

#endif