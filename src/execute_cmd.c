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

	fprintf(stderr, "Command not supported in Simple Shell: %s\n", cmd_args[0]);

#ifdef RUN_UNSUPPORTED_CMD
	return execute_unsupported_cmd(cmd_args);
#else
	return -1;
#endif
}

#ifdef RUN_UNSUPPORTED_CMD

/**
 * execute_unsupported_cmd - Execute an unsupported command in a new process.
 *
 * This function forks a new process to execute the given command using `execvp`.
 * If the command is not found or an error occurs, an error message is printed.
 * The parent process waits for the child process to complete.
 *
 * @args: The array of command-line arguments, with the command as the first element.
 *
 * Return: Always returns -1 to indicate the function execution is complete.
 */
int execute_unsupported_cmd(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid ==  0) //Child process
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Error in execute_unsupported_cmd: Command Execution failed!");
		}
		exit(EXIT_FAILURE);
	}
	else if(pid>0) //Parent Process
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else //Fork error
	{
		perror("Error in execute_unsupported_cmd: Fork failed!");
	}
	return -1;
}

#endif /*RUN_UNSUPPORTED_CMD*/