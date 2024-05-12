#include "func_impl.h"

/**
 * cd_impl - Change the working directory of the current shell execution environment.
 *
 * This function implements the "cd" built-in command to change the current working directory.
 * If no argument is provided, an error message is printed to stderr.
 * If the specified directory does not exist or cannot be accessed, an error message is printed using perror.
 *
 * @cmd_args: An array of command-line arguments. The second argument (cmd_args[1]) is the target directory.
 *
 * Return: Always returns -1 to indicate completion.
 */
int cd_impl(char **cmd_args)
{
	// Check if an argument (target directory) is provided
	if (cmd_args[1] == NULL)
	{
		fprintf(stderr, "Usage: cd <directory>\n");
	}
	else
	{
		// Attempt to change the directory
		if (chdir(cmd_args[1]) != 0)
		{
			perror("Error in cd_impl: chdir\n");
		}
	}
	return (-1);
}