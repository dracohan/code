#include "apue.h"

int
main()
{
#ifdef _TEST
	printf("_TEST is defined\n");
#else
	printf("_TEST is not defined\n");
#endif
	exit(0);
}