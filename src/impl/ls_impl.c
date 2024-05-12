#include <dirent.h>
#include <sys/stat.h> 

#include "func_impl.h"

/**
 * ls_impl - List the contents of a directory.
 *
 * This function implements the "ls" built-in command to list the contents of
 * a directory. It takes an optional directory path as an argument. If no path
 * is provided, it lists the contents of the current working directory.
 *
 * @args: An array of command-line arguments. The second argument (args[1]) is
 *        the optional directory path.
 *
 * Return: Always returns -1 to indicate completion. If an error occurs, the
 *         function may terminate the program with an appropriate error message.
 */
int ls_impl(char **args) {
    (void)(**args); // Suppress unused parameter warning

    char *dir_path = args[1]; // Directory path (if provided)

    // Open the directory (use current directory if no path is provided)
    DIR *dir = opendir(dir_path ? dir_path : ".");
    if (!dir) {
        perror("Error in ls_impl: opendir. Usage: ls <directory path>");
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        write(STDOUT_FILENO, entry->d_name, strlen(entry->d_name));
        write(STDOUT_FILENO, "\n", 1);
    }

    closedir(dir);

    return -1;
}