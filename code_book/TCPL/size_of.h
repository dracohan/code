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


//��СΪ0�ķǶ������󣬱�����������һ��char���ն�����
class Empty {
	enum EmptyEnum{ ENUM1, ENUM2, ENUM3};
	static int x;
	//virtual ���������������Ĵ�С����1��Ϊ4
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