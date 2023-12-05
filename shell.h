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

#endif
