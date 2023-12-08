#include "shell.h"

/**
 * _erratoi - converts string to numb
 * @str: string
 * Return: 0 or -1
 */
int _erratoi(char *str)
{
	int i = 0;
	unsigned long conv = 0;

	if (!str)
		return (0);
	if (*str == '+')
		str++;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			conv *= 10;
			conv += (str[i] - '0');
			if (conv > INT_MAX)
				return (-1);
		}
		else
		{
			return (-1);
		}
	}

	return (conv);
}

/**
 * _eputs - prints an input
 * @str: String
 */
void _eputs(char *str)
{
	int i = 0;

	if (str == NULL)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - print a character to stderr
 * @c: Character
 * Return: 1 or -1
 */
int _eputchar(char c)
{
	int i;
	char buffer[1024];

	if (c == -1 || i >= 1024)
	{
		write(2, buffer, i);
		i = 0;
	}
	if (c != -1)
		buffer[i++] = c;

	return (1);
}

/**
 * _putfd - print character to fd
 * @c: Character
 * @fd: File
 * Return: 1 or -1
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buffer[1024];

	if (c == -1 || i >= 1024)
	{
		write(fd, buffer, i);
		i = 0;
	}

	if (c != -1)
		buffer[i++] = c;
	return (1);
}
