///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   inherite.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/24 09:43:20
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
  
#include "inherite.h"
#include <iostream>
using namespace std;

void invoker(Base* pb)
{
	pb->public_virtual_func();
}

int main()
{
	Base b;
	
	cout << "1======================" << endl;
	//对象可以调用public的函数
	b.public_func();
	b.public_virtual_func();
	cout << endl;
	
	//对象不可以访问protected和private函数与对象
	//b.protected_func();
	//b.protected_virtual_func();
	//b.private_func();
	//b.private_virtual_func();
	
	cout << "2======================" << endl;
	//基类的非虚函数不能覆盖否则通过基类和派生类调用他的结果不同
	//1.
	Base* pb = new Derived;
	pb->public_func();
	delete pb;
	cout << endl;
	//2. 
	Derived* pd = new Derived;
	pd->public_func();
	delete pd;
	cout << endl;
	
	cout << "3======================" << endl;
	//对象可以调用public函数
	Derived d;
	d.public_func_caller();
	//public继承，派生类对象可以访问基类public函数
	d.public_virtual_func();
	//同样不能调用protected成员与private成员
	//d.protected_virtual_func();
	//d.private_virtual_func();
	cout << endl;
	
	cout << "4======================" << endl;
	//Derived2 d2;
	//private继承，则对象连基类的public函数也不能访问
	//d2.public_virtual_func();
	//cout << endl;
	
	Base* pbb = new Base;
	Base* pbd = new Derived;
	//private继承则不能将派生类对象转换为基类指针，因为认为这只是实现继承，不继承任何接口
	//Base* pbd2 = new Derived2;
	invoker(pbb);
	invoker(pbd);
	//虽然封装一次调用关系，但是virtual机制依然生效
	pbd->public_virtual_func_caller();
	//invoker(pbd2);
	delete pbb;
	delete pbd;
	//delete pbd2;
	cout << endl;
	
	cout << "5======================" << endl;
	//private继承的对象可以调用
	Derived3 d3;
	d3.public_virtual_func();
	cout << endl;
	
	return 0;	
}
