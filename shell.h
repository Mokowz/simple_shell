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
} info_t;

#define BUF_FLUSH -1

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, NULL, NULL, NULL, 0, 0, 0, NULL, 0}

ssize_t buffer_input(info_t *info, char **buffer, size_t *length);
ssize_t get_input_line(info_t *info);
ssize_t read_buffer(info_t *info, char *buffer, size_t *index);
int _getline(info_t *info, char **pointer, size_t *length);
int _myenv(info_t *info);
char *_getenv(info_t *info, const char *name);
int _mysetenv(info_t *info);
int _myunsetenv(info_t *info);
int populate_env_list(info_t *info);
int _myexit(info_t *info);
int _mycd(info_t *info);
int _myhelp(info_t *info);
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

#endif
