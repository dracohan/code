///////////////////////////////////////////////////////////////////////////////
//                                               
//  FileName    :   effect_item9.h                                                                                                   
//  Author      :   Ryan Han                                                                                                     
//  Date        :   2013/11/01 15:43:35                                                                                          
//  Comment     :                                                                                                                
//	�����ڹ������������������麯������Ϊ�ڹ����ڼ�virtual��������virtual��
//	�����virtual�������¸ú����ܿ��ܷ���δ����ı���
///////////////////////////////////////////////////////////////////////////////

#ifndef _EFFECT_ITEM9_H_
#define _EFFECT_ITEM9_H_

#include <iostream>
using namespace std;

class B {
	public:
		~B() {
			cout << "~B() was called. " << endl;
			clearAll();
		}
		
		void clearAll(){
			//will never called derived pureVirtual() because after ~D(), there will be only B left. 
			pureVirtual();
		}
		
	private:
		virtual void pureVirtual() = 0;
};

class D : public B{
	public:
		~D() {
			cout << "~D() was called. " << endl;
		}
	private:
		virtual void pureVirtual();
};
	

#endif
