///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   extern_usage0.cc
//  Version     :   0.10	created	2014/05/00 00:00:00		
//  Author      :   Jimmy Han
//  Comment     :  在别的cc文件里定义的变量可以在本cc文件里加extern声明
//
///////////////////////////////////////////////////////////////////////////////
#include "extern_usage.h"
#include <iostream>

extern abc a;

int
main()
{
	a.test();
	return true;
}