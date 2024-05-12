#include "cmd_exec.h"

/**
 * read_cmd - Read a line from standard input (stdin).
 *
 * This function reads a line from standard input (stdin) using the getline function.
 * It dynamically allocates memory to store the line and returns a pointer to the
 * allocated memory containing the line content.
 *
 * Return: A pointer to a dynamically allocated string containing the line content.
 *         The caller is responsible for freeing the allocated memory.
 *         If an error occurs during reading, the function may terminate the program
 *         with an appropriate error message.
 */
char *read_cmd(void)
{
	char *cmd = NULL;
	size_t cmdSize = 0;

	// Attempt to read a line from stdin using the getline function
	if (getline(&cmd, &cmdSize, stdin) == -1)
	{
		if (feof(stdin))
		{
			// If the end-of-file (EOF) is reached (e.g., Ctrl+D), exit gracefully
			free(cmd);
			exit(EXIT_SUCCESS);
		}
		else
		{
			// If an error occurs, print an error message and exit with failure
			free(cmd);
			perror("Error while reading the line from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (cmd);
}

/**
 * tokenize_cmd - Tokenize a string into multiple strings.
 *
 * This function splits a string into multiple tokens using the strtok function.
 * It dynamically allocates memory to store the tokens and returns a pointer to
 * the allocated memory containing the array of tokens.
 *
 * @cmd: The string to be tokenized.
 *
 * Return: A pointer to a dynamically allocated array of strings (tokens).
 *         The last element of the array is set to NULL to indicate the end of tokens.
 *         The caller is responsible for freeing the allocated memory.
 *         If an error occurs during memory allocation, the function may terminate
 *         the program with an appropriate error message.
 */
char **tokenize_cmd(char *cmd)
{
	int tokensSize = 64;
	int i = 0;
	char **tokens = malloc(tokensSize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Allocation error in tokenize_cmd: tokens\n");
		exit(EXIT_FAILURE);
	}
	
	token = strtok(cmd, DELIMS);
	while (token != NULL)
	{
		// Check for comments (lines starting with '#')
		if (token[0] == '#') {
			break;
		}

		tokens[i] = token;
		i++;

		if (i >= tokensSize) {
			tokensSize += tokensSize;
			tokens = realloc(tokens, tokensSize * sizeof(char *));
			if (!tokens) {
				fprintf(stderr, "Reallocation error in tokenize_cmd: tokens\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIMS);
	}

	tokens[i] = NULL;
	return (tokens);
}