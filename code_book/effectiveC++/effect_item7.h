///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   effect_item7.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/11/01 14:24:35
//  Comment     :  
//	A的析构函数必须为virtual，否则，AA的私有变量将不会被析构
///////////////////////////////////////////////////////////////////////////////

#ifndef _EFFECT_ITEM7_H_
#define _EFFECT_ITEM7_H_

#include <iostream>
using namespace std;

class B {
    public:
		//deconstructor can't be private
	    //private:
	    ~B(){
	    	cout << "B deconstructor was called" << endl;
	    }
};

//D is abstract class
class D : public B {
	//private function could be public in derived class
	private:
		virtual void pureVirtualFunc() = 0;
};

//DD has to implement void pureVirtualFunc() to be concrete
class DD : public D {
	public:
		void pureVirtualFunc();
};

class A {
	public:
		virtual void VirtualFunc(){
			cout << "A::VirtualFunc() was called" << endl;
		}
		//deconstructor is virtual, OK
		virtual ~A(){
			cout << "A::~A() was called" << endl;
		}
};
	
class AA : public A {
	public:
		//AA has to declare virtual void VirtualFunc() before implement it
		void VirtualFunc();
	
		//AA will not called when call delete pA;
		~AA(){
			cout << "AA::~AA() was called" << endl;
		}
	private:
		int _size;
};
	
	

#endif
