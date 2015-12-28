///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   effect_item33.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/26 16:50:14
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#ifndef EFFECT_ITEM33_H
#define	EFFECT_ITEM33_H

class base{
public:
	virtual void mf1() = 0;
	virtual void mf1(int);
	virtual void mf2();
	void mf3();
	void mf3(double);
private:
	int x;
};

class derive : public base {
public:
	using base::mf1;
	void mf1();
	void mf4();
private:
	int y;
};

#endif