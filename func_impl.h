#ifndef FUNC_IMPL_H
#define FUNC_IMPL_H

#include "common.h"

typedef struct {
    const char *name;
    int (*func)(char **);
} SupportedCmd;

int cd_impl(char **args);
int exit_impl(char **args);
int env_impl(char **args);
int pwd_impl(char **args);

#endif