#include "apue.h"
#include "my_err.h"

int
main()
{
	int a = 10;
	pid_t pid;

	char buf[] = "asdf\n";
	if(write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
		err_sys("write error");

	//printf("the size of buf is %d\n", sizeof(buf));

	printf("before forking\n");

	if((pid = fork()) < 0)
		err_sys("err fork execution");
	else if (pid == 0)
		a++;
	else
		sleep(1);

	printf("the value of a is %d\n", a);

	exit(0);
}