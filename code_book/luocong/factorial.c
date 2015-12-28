///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   factorial.cﬂ
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/01 10:12:30
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>

static long factorial(const long n)
{
	return 0 == n || 1 == n ? 1 : n*factorial(n-1);
}

int main()
{
	long lResult = factorial(5);
	printf("The resutl is: %ld\n", lResult);
}
