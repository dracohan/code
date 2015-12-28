///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   deepinherite.h
//  Version     :   0.10	created	2013/12/02 00:00:00		
//  Author      :   Jimmy Han
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#ifndef DEEPINHERITE_H
#define DEEPINHERITE_H
class B1{
public:
	void B1F1();
protected:
	void B1F2();
private:
	void B1F3();
};

class D1 : public B1{
public:
	void D1T();
};

class D2 : public D1{
public:
	void D2T();
};

class D3 : private D1{
public:
	void D3T();
};

#endif