///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   no_virtual_func_in_stor_item09.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/s 16:51:03
//  Comment     :  
//	virtual function在构造期间不会被下放到derive的类，因为会导致访问未定义变量
///////////////////////////////////////////////////////////////////////////////

#ifndef __H__
#define __H__

class Shape {
	public: 
		Shape();
		virtual void LogTransation();
		
};

class Rectangel : public Shape {
	public:
		Rectangel();
		virtual void LogTransation();
};

#endif