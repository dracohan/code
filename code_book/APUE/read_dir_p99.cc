#include "apue.h"
#include "my_err.h"
#include <fcntl.h>

typedef int Myfunc(const char*, const struct stat*, int);
static	Myfunc 	myfunc;
static	int		myftw(char*, Myfunc*);
static	int		dopath(Myfunc*);
static	long nreg, ndir, nblk, nchr, nfifo, nslink, nsock, ntot;

int
main()
{
	int		ret;
	if(arg != 2)
		err_quit("usage: ftw <starting pathname>");

	ret = myftw(argv[1], myfunc);

	ntot = nreg + ndir + nblk + nchr + nfifo + nslink + nsock;


}

#define FTW_F	1
#define	FTW_D	2
#define	FTW_DNR	3
#define	FTW_NS	4

static char* fullpath;

static int
myftw(char* pathname, Myfunc* func)
{
	int len;
	fullpath = path_alloc(&len);

	strncpy(fullpath, pathname, len);
	fullpath[len-1] = 0;

	return(dopath(func));
}

static int
dopath(Myfunc* func)
{
	struct stat 	statbuf;
	struct dirent	*dirp;
	DIR 			*dp;
	int 			ret;
	char			*ptr;

	if(lstat(fullpath, &statbuf) < 0)
		return(func(fullpath, &statbuf, FTW_NS));
	if(S_ISDIR(statbuf.mode) == 0)
		return(func(fullpath, &statbuf, FTW_F));
	
}
