#include "func_impl.h"

/**
 * exit_impl - Exit the shell.
 *
 * This function implements the "exit" built-in command for terminating the shell.
 * If an argument is provided, it is interpreted as the exit status; otherwise, the default exit status is 0.
 *
 * @args: An array of command-line arguments. The first argument is expected to be "exit",
 *        and the second argument, if present, is the exit status.
 *
 * Return: If an argument is provided, the function returns the exit status converted to an integer.
 *         If no argument is provided, the function returns 0 to indicate successful termination.
 */
int exit_impl(char **args)
{
	if (args[1])
	{
		return (atoi(args[1]));
	}
	else
	{
		return (0);
	}
}