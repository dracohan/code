///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   fic.cﬂ
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/01 10:12:30
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>

static long fib(const long n)
{
	return 0 == n || 1 == n ? 1 : fib(n - 1) + fib(n - 2);
}

int main()
{
	//F0=0£¨F1=1£¨Fn=F(n-1)+F(n-2)£®n>=2£¨n° N*£©
	long lResult = fib(5);
	printf("The resutl is: %ld\n", lResult);
}