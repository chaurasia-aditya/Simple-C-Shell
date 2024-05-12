#include "func_impl.h"

/**
 * pwd_impl - Print the current working directory.
 *
 * This function implements the "pwd" command to print the current working directory.
 * It uses the getcwd function to retrieve the current working directory and then prints it to
 * the standard output (stdout). If an error occurs while retrieving the current working directory,
 * an error message may be printed to stderr.
 *
 * @args: An array of command-line arguments. This parameter is not used in this function.
 *
 * Return: Always returns -1 to indicate completion. If an error occurs, the function may terminate
 *         the program with an appropriate error message.
 */
int pwd_impl(char **args)
{
	(void)(**args); // Unused parameter warning is suppressed
	char cwd[1024]; 

    // Attempt to retrieve the current working directory
    if (getcwd(cwd, sizeof(cwd)) != NULL) {

        write(STDOUT_FILENO, cwd, strlen(cwd));
        write(STDOUT_FILENO, "\n", 1);
    } else {
        perror("Error in pwd_impl: getcwd\n");
    }
	
	return (-1);
}