#include "apue.h"
#include "my_err.h"
#include <fcntl.h>
int
main(int argc, char* argv[])
{
	int		ret;
		/* code */
		if (access(argv[1], R_OK) < 0)
			err_ret("error read access for %s", argv[1]);
		else
			printf("read access OK");

		if (access(argv[1], W_OK) < 0)
			err_ret("error write access for %s", argv[1]);
		else
			printf("write access OK");
		if (access(argv[1], O_RDONLY) < 0)
			err_ret("error access for %s", argv[1]);
		else
			printf("open for reading OK");
		exit(0);	
}
 
 +