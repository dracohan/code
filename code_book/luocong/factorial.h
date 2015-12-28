///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   factorial.c
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/06/31 10:12:30
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>

static long factorial(const long n)
{
	return 0 == n || 1 == n ? 1 : n*factorial(n-1);
}
	