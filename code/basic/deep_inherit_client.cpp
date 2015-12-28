///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   deep_inherit_client.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2014/6/19 15:03
//  Comment     :  
//	Output		:
// $ ./a.out
// B1ELEM::B1ELEM() was called
// B2ELEM::B2ELEM() was called
// D1ELEM::D1ELEM() was called
// D2ELEM::D2ELEM() was called
// D3ELEM::D3ELEM() was called
// D4ELEM::D4ELEM() was called
// ====================================
// B1ELEM copy constructor was called
// B2ELEM copy constructor was called
// base1::base1() was called
// D1ELEM copy constructor was called
// D2ELEM copy constructor was called
// derive1::derive1() was called
// D3ELEM copy constructor was called
// D4ELEM copy constructor was called
// derive2::derive2() was called
//注意：如果base1, derive1, derive2的构造函数不是引用传递则会引起三次调用构造函数的参数拷贝
///////////////////////////////////////////////////////////////////////////////
#include "deep_inherit.h"
#include <iostream>
using namespace std;

int main() {
	B1ELEM b1;
	B2ELEM b2;
	D1ELEM d1;
	D2ELEM d2;
	D3ELEM d3;
	D4ELEM d4;

	cout << "====================================" << endl;
	derive2 d(b1, b2, d1, d2, d3, d4);
	
	return 0;
}



	


