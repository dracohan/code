#include "apue.h"
#include "my_err.h"
#include <pwd.h>
#include <stddef.h>
#include <string.h>

struct passwd *
getpwnam(const char* name)
{
	struct passwd *ptr;
	setpwent();
	while((ptr = getpwent()) != NULL)
		if(strcmp(name, ptr->pw_name) == 0)
			break;
	enpwent();
	return(ptr);
}