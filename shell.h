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

int _putchar(char);
void _puts(char *);
int _mystrlen(char *);
char *_strdup(char *);
char *_concat(char *, char *, char *);

char **split_string(char *str, const char *delim);
void _execute(char **args);
void *_myrealloc(void *ptr, unsigned int old_size, unsigned int new_size);

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

/**
 * struct list_pathname - linked list
 * @data: Path
 * @path: pointer to next
 */
typedef struct list_pathname
{
	char *data;
	struct list_pathname *path;
} list_pathname;


void custom_exit(char **args);
int _atoi(char *str);
void _mysetenv(char **args);
void _myunsetenv(char **args);
void(*check_builtin(char **args))(char **args);
void _env(char **args);
char *_mygetenv(const char *name);

void freeargs(char **args);

/* pathname */
list_pathname *linkpathname(char *);
char *getenviron(const char *);
list_pathname *add_node_to_end(list_pathname **, char *);
void flist(list_pathname *);
char *which_path(char *, list_pathname *);

/* more */
void isterm(void);
void end_file(int, char *);
void sigHandler(int);


#endif
