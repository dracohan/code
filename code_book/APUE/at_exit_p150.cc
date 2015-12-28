#include "apue.h"
#include "my_err.h"

void my_exit1();
void my_exit2();


int
main()
{
	if(atexit(my_exit1) != 0)
		err_sys("register my_exit1 failed");
	if(atexit(my_exit1) != 0)
		err_sys("register my_exit1 failed");
	if(atexit(my_exit2) != 0)
		err_sys("register my_exit1 failed");

}

void
my_exit1()
{
	printf("my exit1\n");
}


void
my_exit2()
{
	printf("my exit2\n");
}



