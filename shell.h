#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


extern char **environ;

/**
 * struct lists - singly linked list
 * @num: Number
 * @str: String
 * @next: Next pointer
 */
typedef struct lists
{
	int num;
	char *str;
	struct lists *next;
} list_t;

/**
 * struct pseudoargs - contains pseudo arguments to pass to functions
 * @argument: String from getline
 * @argv: Array of strings
 * @path: Path of curent cmd
 * @argc: Argument count
 * @line_count: Error count
 * @fname: Filename
 * @env: Linked list
 * @alias: Alias node
 * @linecount_flag: if on count this line
 * @status: return status of the last exec
 * @err_num: umber of erorr
 * @cmd_buffer: Address of pointer of cmd_buf
 * @cmd_buffer_type: for || && ;
 * @readfd: fd to read line from
 * @histcount: history line
 * @environ_changed: Emvironment changed
 */
typedef struct pseudoargs
{
	char *argument;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int readfd;
	char *fname;
	list_t *env;
	list_t *alias;
	int status;
	int linecount_flag;
	int err_num;
	char **cmd_buffer;
	int cmd_buffer_type;
	int histcount;
	int environ_changed;
	list_t *hist;
} info_t;

#define BUF_FLUSH -1

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, NULL, NULL, NULL, 0, 0, 0, NULL, 0, 0, 0, NULL}
/* get_line.c funts */
ssize_t buffer_inp(info_t *info, char **buffer, size_t *length);
ssize_t get_input(info_t *info);
ssize_t read_buf(info_t *info, char *buffer, size_t *index);
int _getline(info_t *info, char **pointer, size_t *length);
void sigintHandler(int signum);
void check_chain(info_t *, char *, size_t*, size_t, size_t);
int build_hist_list(info_t *info, char *buf, int linecount);
int is_chain(info_t *, char *, size_t *);

/* env.c functs */
int _monenv(info_t *info);
char *_getenv(info_t *info, const char *name);
int _monsetenv(info_t *info);
int _monunsetenv(info_t *info);
int pop_env_list(info_t *info);
size_t print_list_str(const list_t *);
list_t *add_node_end(list_t **, const char *, int);

/* builtin exit functs */
int _monexit(info_t *info);
int _moncd(info_t *info);
int _monhelp(info_t *info);
int _setenv(info_t *, char *, char *);
int _unsetenv(info_t *, char *);

/* atoi functs */
int interactive(info_t *info);
int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);

/* strtok.c file */
char **_strtok(char *str, char *delim);

/* str_functs.c file */
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
void _puts(char *str);
int _putchar(char c);
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
char *starts_with(const char *str, const char *small);
char *_strcat(char *dest, char *src);

/* str3.c file */
char *_strchr(char *str, char c);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);

/* allocate.c file */
char *_memset(char *str, char fill, unsigned int n);
void ffree(char **str);
void *_realloc(void *ptr, size_t old_size, size_t new_size);

/* error file functs */
int _putfd(char c, int fd);
int _eputchar(char c);
void _eputs(char *str);
int _erratoi(char *str);
void print_error(info_t *, char *str);
int print_d(int inp, int fd);
void remove_comments(char *buffer);

/* more c */
void check_chain(info_t *info, char *buffer, size_t *posi, size_t i, size_t len);
int is_chain(info_t *info, char *buffer, size_t *posi);

int _setenv(info_t *info, char *var, char *val);
int _unsetenv(info_t *info, char *var);
#endif
