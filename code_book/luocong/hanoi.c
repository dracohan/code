///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   hanoi.c
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/01 10:55:30
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
static void move(const char x, const int n, const char z)
{
	printf("Move planet %d from pole %c to %c \n", n, x, z);
}

static void hanoi(const int n, const char x, const char y, const char z)
{
	if(1 == n)
		move(x, 1, z);
	else
	{
		hanoi(n-1, x, z, y);
		move(x, n, z);
		hanoi(n-1, y, x, z);
	}
}

int main()
{
	hanoi(4, 'X', 'Y', 'Z');
}
