///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   no_virtual_func_in_stor_item09.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/s 16:51:03
//  Comment     :  
//	virtual function�ڹ����ڼ䲻�ᱻ�·ŵ�derive���࣬��Ϊ�ᵼ�·���δ�������
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