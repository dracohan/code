///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   deep_inherit.h
//  Version     :   0.10
//  Author      :   Jimmy Han
//  Date        :   2014/6/19 15:03
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#ifndef DEEP_INHERIT_H
#define	DEEP_INHERIT_H

class B1ELEM{
public:
	B1ELEM();
	B1ELEM(const B1ELEM &b1);
};
class B2ELEM{
public:
	B2ELEM();
	B2ELEM(const B2ELEM &b2);
};

class D1ELEM{
public:
	D1ELEM();
	D1ELEM(const D1ELEM &d1);
};
class D2ELEM{
public:
	D2ELEM();
	D2ELEM(const D2ELEM &d2);
};

class D3ELEM{
public:
	D3ELEM();
	D3ELEM(const D3ELEM &d3);
};
class D4ELEM{
public:
	D4ELEM();
	D4ELEM(const D4ELEM &d4);
};


class base1{
public:
	base1(const B1ELEM &b1, const B2ELEM &b2);
	void base1Func();
private:
	B1ELEM base1Elem;
	B2ELEM base2Elem;
};

class derive1 : public base1 {
public:
	derive1(const B1ELEM &b1, const B2ELEM &b2, const D1ELEM &d1, const D2ELEM &d2);
	void derive1Func();
private:
	D1ELEM derive1Elem;
	D2ELEM derive2Elem;
};

class derive2 : public derive1 {
public:
	derive2(const B1ELEM &b1, const B2ELEM &b2, const D1ELEM &d1, const D2ELEM &d2, const D3ELEM &d3, const D4ELEM &d4);
	void derive2Func();
private:
	D3ELEM derive3Elem;
	D4ELEM derive4Elem;
};




#endif