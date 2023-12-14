#include "shell.h"

/**
 * _putchar - write a character to stdout
 * @c: Character
 * Return: 1 or -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - print string
 * @str: String
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _mystrlen - length of string
 * @str: String
 * Return: lenght
 */
int _mystrlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
