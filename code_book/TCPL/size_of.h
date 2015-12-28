///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   size_of.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/10/31 14:17:45
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////

#ifndef __H__
#define __H__


//大小为0的非独立对象，编译器将插入一个char到空对象中
class Empty {
	enum EmptyEnum{ ENUM1, ENUM2, ENUM3};
	static int x;
	//virtual 函数将增加类对象的大小，从1变为4
	//virtual ~Empty();
};


class HoldAnInt {
	int a;
	Empty e;
};

class NonVirtualDerived : public Empty {
};

class VirtualDerived : virtual public Empty {
};

#endif