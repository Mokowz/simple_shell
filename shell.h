#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

int _putchar(char c);
int puts(char *str);
int _mystrlen(char *s);
int *strdup(char *str);
char *concat_all(char *name, char *sep, char *value);

char **split_string(char *str, const char *delim);
void _execute(char **args);
void *realloc(void *ptr, unsigned int old_size, unsigned int new_size);

extern char **environ;

/**
 * struct _mybuild - pointer to fxn corresponding builtin command
 *
 * @name: builtin command
 * @func: execute the builtin command
 */
typedef struct _mybuild
{
	char *name;
	void (*func)(char **);
} _mybuild;

void custom_exit(char **args);
int _atoi(char *str);
void _mysetenv(char **args);
void _myunsetenv(char **args);
void(*check_builtin(char **args))(char **args);
void _env(char **args);
char *_mygetenv(const char *name);

void freeargs(char **args);

#endif
