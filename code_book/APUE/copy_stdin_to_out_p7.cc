#include "apue.h"
#include "my_err.h"

int
main(int argc, char* argv[])
{
	int			c;

	while((c = getc(stdin)) != EOF)
		if(putc(c, stdout) == EOF)
			err_sys("write err");

	if(c < 0)
		err_sys("read err");

	exit(0);
}

#ifdef 0
int
main()
{
	char	buf[MAXLINE];

	while(fgets(buf, MAXLINE, stdin) != NULL)
		if(fputs(buf, stdout) == EOF)
			err_sys("output error");

	if(ferror(stdin))
		err_sys("input error");

	exit(0);
}

#endif m