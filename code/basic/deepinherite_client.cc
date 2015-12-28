///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   deepinherite_client.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/12/02
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "deepinherite.h"
using namespace std;

int main(){
	B1* pb1 = new D1;
	pb1->B1F1();
	//对象不能调用protected和private成员变量
	//pb1->B1F2();
	//pb1->B1F3();
	delete pb1;

	D1* pd1 = new D1;
	pd1->D1T();
	delete pd1;

	D2* pd2 = new D2;
	pd2->D2T();
	delete pd2;
}