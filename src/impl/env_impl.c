#include "func_impl.h"
#include "utils.h"

/**
 * env_impl - Print environment variables to standard output.
 *
 * This function prints the current environment variables to the standard output.
 * Each environment variable is printed on a separate line.
 *
 * @args: The array of command-line arguments. This parameter is not used in this function.
 *
 * Return: Always returns -1 to indicate that the function execution is complete.
 *         This function does not perform error checking on the environment variables.
 */
int env_impl(char **args)
{
	(void)(**args); // Unused parameter warning is suppressed
    int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (-1);
}