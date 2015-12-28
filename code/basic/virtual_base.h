//////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   virtual_base.h
//  Version     :   0.10	created	2013/11/16 23:18:03
//  Author      :   Jimmy Han
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

//CHECK VIRTUAL DERIVE CLASS SIZE
class b1{
	virtual void foo_b1();
};

class d1:public b1{

};

class b2{
	virtual void foo_b2();
};

//virtual derived don't occupy space if base has no data
class d2:virtual public b2{

};

class b3{
	virtual void foo_b3();
	char a;
};

class d3:public b3{

};

class b4{
	virtual void foo_b4();
	char a;
};

//virtual derived occupy 4 bytes space if base has data
class d4:virtual public b4{
	
};

//CHECK CONSTRUCTOR/DECONSTRUCTOR SEQUENCE
class b5{
public:
	b5(){cout << "b5() constructed. " << endl;}
	~b5(){cout << "b5() deconstructed. " << endl;}
};

class d51:virtual public b5{
	public:
	d51(){cout << "d51() constructed. " << endl;}
	~d51(){cout << "d51() deconstructed. " << endl;}
};

class d52:virtual public b5{
	public:
	d52(){cout << "d52() constructed. " << endl;}
	~d52(){cout << "d52() deconstructed. " << endl;}
};

class d6:public d51, public d52{
	public:
	d6(){cout << "d6() constructed. " << endl;}
	~d6(){cout << "d6() deconstructed. " << endl;}
};

//http://blog.csdn.net/dqjyong/article/details/8028888
class B1
{
public:
    B1(){cout<<"B1::B1()!<"<<endl;}
    void f() {cout<<"i'm here!"<<endl;}
};

class V1: public B1
{
public:
    V1(){cout<<"V1::V1()!<"<<endl;}
};

class D1: virtual public V1
{
public:
    D1(){cout<<"D1::D1()!<"<<endl;}
};

class B2
{
public:
    B2(){cout<<"B2::B2()!<"<<endl;}
};

class B3
{
public:
    B3(){cout<<"B3::B3()!<"<<endl;}
};

class V2:public B1, public B2
{
public:
    V2(){cout<<"V2::V2()!<"<<endl;}
};

class D2:virtual public V2, public B3
{
public:
    D2(){cout<<"D2::D2()!<"<<endl;}
};

class M1
{
public:
    M1(){cout<<"M1::M1()!<"<<endl;}
};

class M2
{
public:
    M2(){cout<<"M2::M2()!<"<<endl;}
};

class X:public D1, public D2
{
    M1 m1;
    M2 m2;
};
