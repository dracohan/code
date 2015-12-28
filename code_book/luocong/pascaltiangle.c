///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   pascaltriangle.c
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/01 11:25:30
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
static long GetElement(const long row, const long col)
{
	//1
	//1   1
	//1   2   1
	//1   3   3   1
	//1   4   6   4   1

	if(1 == col || col == row)
		return 1;
	else
		return GetElement(row - 1, col - 1) + GetElement(row - 1, col);
}

static long PascalTriangle(const long n)
{
	int row, col;
	
	for(row = 1; row <= n; ++row)
	{
		for(col = 1; col <= row; ++col)
			printf("%4ld", GetElement(row, col));
		printf("\n");
	}
}

int main()
{
	PascalTriangle(5);
}

