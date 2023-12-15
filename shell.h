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

char **split_string(char *, const char *);
void _execute(char **);
void *_myrealloc(void *, unsigned int, unsigned int);

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


void custom_exit(char **);
int _atoi(char *);
void _mysetenv(char **);
void _myunsetenv(char **);
void(*check_builtin(char **))(char **);
void _env(char **);
char *_mygetenv(const char *);

void freeargs(char **);

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
