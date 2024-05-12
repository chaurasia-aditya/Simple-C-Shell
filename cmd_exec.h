#ifndef CMD_EXEC_H
#define CMD_EXEC_H

#include "common.h"

#define DELIMS " \t\r\n\a\""

char *read_cmd(void);
char **tokenize_cmd(char *line);

int execute_cmd(char **args);

#endif