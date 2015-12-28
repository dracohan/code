///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   use_private_inherit_judiciously_item39.h_client.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/23 16:52:33
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
  
#include "use_private_inherit_judiciously_item39.h"
#include <iostream>
using namespace std;

int main()
{
	Rectangel r;
	
	//private继承时，派生类对象不能访问基类public函数或变量
	//r.draw();

	return 0;	
}
