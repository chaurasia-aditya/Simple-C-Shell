#include "cmd_exec.h"
#include "func_impl.h"

// Array of supported commands
SupportedCmd supportedCmds[] = {
    {"cd", cd_impl},
    {"exit", exit_impl},
    {"env", env_impl},
	{"pwd", pwd_impl},
	{"ls", ls_impl}
};

#define NUM_SUPPORTED (sizeof(supportedCmds) / sizeof(SupportedCmd))

/**
 * execute_cmd - Execute a command based on its name.
 *
 * This function checks if the provided command is a supported command
 * and executes the corresponding function. If the command is not supported,
 * it prints an error message to stderr.
 *
 * @cmd_args: An array of strings representing the command and its arguments.
 *
 * Return: Returns response from command handler on execution of a supported command,
 *         or -1 if the command is not supported.
 */
int execute_cmd(char **cmd_args)
{
	long unsigned int i = 0;

	if (cmd_args[0] == NULL)
	{
		// No command
		return (-1);
	}

	for (; i < NUM_SUPPORTED; i++)
	{
		if (strcmp(cmd_args[0], supportedCmds[i].name) == 0)
		{
			return (supportedCmds[i].func(cmd_args));
		}
	}

	fprintf(stderr, "Command not supported: %s\n", cmd_args[0]);
    return -1;
}