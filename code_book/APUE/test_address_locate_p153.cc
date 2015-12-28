#include "apue.h"
#include "my_err.h"
#include <stdio.h>

void printaddr(int addr);

int 
main()
{
	//un-initialized stack
	int i, j;
	int k;

	//initialized stack
	int m = 0;
	int n = 1;

	//heap;
	int* pi = new int(3);
	int* pj = new int(4);

	//print the address
	
	printaddr(int(&i));
	printaddr(int(&j));
	printaddr(int(&k));
	printaddr(int(&m));
	printaddr(int(&n));
	printaddr(int(pi));
	printaddr(int(pj));
	
	//printf("0x%08x\n", pi);

}































void
printaddr(int addr)
{
	printf("0x%08x\n", addr);
}