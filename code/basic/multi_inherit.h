///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   multi_inherit.h
//  Version     :   0.10	created	2013/11/08 00:00:00		
//  Author      :   Jimmy Han
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#ifndef MULTI_INHERIT_H
#define	MULTI_INHERIT_H

class base1{
public:
	void baseFunc();
private:
	int baseElem;
};

class derive1 : public base1 {
public:
	void derive1Func();
private:
	int derive1Elem;
};

class base2{
public:
	void baseFunc();
private:
	int baseElem;
};

class derive2 : public derive1, public base2{
public:
	void derive2Func();
	
	//to avoid ambigous
	void baseFunc();
	
private:
	int derive2Elem;
};

#endif