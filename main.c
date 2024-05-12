#include "shell.h"

/**
 * main - Entry point of the program.
 *
 * This function serves as the entry point of the program. It calls the `shell` function,
 * which initiates the shell's command interpreter loop. The `shell` function repeatedly
 * prompts the user for input, reads commands from standard input, and executes them.
 * Once the `shell` function returns, the program exits with a status of 0, indicating
 * successful execution.
 *
 * Return: Always returns 0 to indicate successful execution.
 */
int main(void)
{
	shell();
	return (0);
}