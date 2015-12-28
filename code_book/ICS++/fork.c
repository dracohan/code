#include "stdio.h"

int Fork(void)
{
	int pid;

	if ((pid = fork()) < 0) 
		exit("Fork error");
	return pid;
}

int main() 
{
	int x =1;

	if (Fork() == 0)
		printf("printf 1: x=%d\n", ++x);
	printf("printf 2: x=%d\n", --x);
	exit(0);
}
