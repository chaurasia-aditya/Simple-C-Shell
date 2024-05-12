#include "func_impl.h"

int pwd_impl(char **args)
{
	(void)(**args); // Unused parameter warning is suppressed
	char cwd[1024]; 

    getcwd(cwd, sizeof(cwd)); 

	write(STDOUT_FILENO, cwd, strlen(cwd));
	write(STDOUT_FILENO, "\n", 1);
	
	return (-1);
}