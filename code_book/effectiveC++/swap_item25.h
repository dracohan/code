///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   swap_item25.h
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/26 13:13:55
//					2013/10/30 08:27:50
//  Comment     :  
//	将Widget声明一个swap的public函数做真正的置换工作，然后将std::swap特化
///////////////////////////////////////////////////////////////////////////////

#ifndef _SWAP_ITEM25_H_
#define _SWAP_ITEM25_H_

#include <iostream>
using namespace std;

class WidgetImpl {
	public: 
		WidgetImpl(int a = 1, int b = 2, int c = 3);
		/*WidgetImpl(int a = 1, int b = 2, int c = 3) : x(a), y(b), z(c){
			cout << "WidgetImpl constructor called." << endl;
		}*/
		
		~WidgetImpl(){
			cout << "WidgetImpl de-constructor called." << endl;
		}
		
		void WidgetPrint(){
			cout << "x = " << x << " y = " << y << " z = "<< z << endl;
		}
	private:
		int x, y, z;
};

class Widget {
	public:
		Widget(int a = 1, int b = 2, int c = 3) : pImpl(new WidgetImpl(a, b, c)){
			cout << "Widget constructor called." << endl;
			;
		}
		
		~Widget(){
			cout << "Widget de-constructor called." << endl;
			delete pImpl;
		}
		
		Widget(const Widget& rhs) {
			pImpl = new WidgetImpl(*(rhs.pImpl));
		}
				
		Widget& operator=(const Widget& rhs){
			*pImpl = *(rhs.pImpl);
		}
		
		void WidgetPrint(){
			pImpl->WidgetPrint();
			//non friend class can't access private data
			//cout << (*pImpl).x << endl;
		}
		
		//has to use because only member function could access private member pImpl
		void swap(Widget& other){
			using std::swap;
			swap(pImpl, other.pImpl);
		}
	private:
		WidgetImpl* pImpl;
};

//inline to avoid duplicate definition
//http://www.cnblogs.com/dracohan/p/3401660.html
namespace std {
	template <>
	inline void swap<Widget>(Widget& a, Widget& b){
		cout << "specialized swap was called" << endl;
		a.swap(b);
	}
}

#endif
