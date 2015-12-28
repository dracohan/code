///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   const_value.cc
//  Version     :   0.10	created	2014/05/10 18:51		
//  Author      :   Jimmy Han
//  Comment     :	const变量地址不能赋予非const的指针
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

int 
main()
{
	const 	string	str = "ads;lfj";
	//compile error
	//string*	pstr = &str;

}