#include "shell.h"
#include "cmd_exec.h"

/**
 * shell - Base shell command interpreter.
 *
 * This function implements a simple shell command interpreter. It repeatedly
 * prompts the user for input, reads the command, tokenizes it, and executes
 * the corresponding command. The shell continues to execute commands until
 * the user exits the shell.
 *
 * Return: This function does not return any value.
 */
void shell(void)
{
	char *cmd;
	char **cmd_args;
	int status = -1;

	do {
		printf("user$ ");

		cmd = read_cmd();
		cmd_args = tokenize_cmd(cmd);
		status = execute_cmd(cmd_args);

		free(cmd);
		free(cmd_args);

		if (status >= 0){
			exit(status);
		}
	} while (status == -1);
}