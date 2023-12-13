#include "shell.h"

/**
 * remove_comments - replace '#' with '\0'
 * @buffer: address of string
 */
void remove_comments(char *buffer)
{
	int i = 0;

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] == '#' && (!i || buffer[i - 1] == ' '))
		{
			buffer[i] = '\0';
			break;
		}
	}
}

/**
 * print_error - print error message
 * @info: struct
 * @str: Error string
 */
void print_error(info_t *info, char *str)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(str);
}

/**
 * print_d - print a decimal number
 * @inp: Input
 * @fd: Filedescriptor
 * Return: number of cahracters
 */
int print_d(int inp, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current, divisor = 1;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (inp < 0)
	{
		_abs_ = inp;
		__putchar('-');
		count++;
	}
	else
	{
		_abs_ = inp;
	}
	while (_abs_ / divisor >= 10)
		divisor *= 10;

	current = _abs_;
	while (divisor > 0)
	{
		__putchar('0' + current / divisor);
		count++;
		current %= divisor;
		divisor /= 10;
	}

	return (count);
}
