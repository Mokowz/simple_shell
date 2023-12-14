#include "shell.h"
/**
 * custom_exit - exits the shell with or without the return of status n
 *
 * @args: array of words of the entered line
 */
void custom_exit(char **args)
{
	int i, n;

	if (args[1])
	{
		n = _atoi(args[1]);
		if (n <= -1)
			n = 2;
		freeargs(args);
		exit(n);
	}
	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
	exit(0);
}
/**
 * _atoi - converts a string into an integer
 *
 * @str: pointer to a string
 * Return: the integer
 */
int _atoi(char *str)
{
	int i, integer, sign = 1;

	i = 0;
	integer = 0;
	while (!((str[i] >= '0') && (str[i] <= '9')) && (str[i] != '\0'))
	{
		if (str[i] == '-')
		{
			sign = sign * (-1);
		}
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		integer = (integer * 10) + (sign * (str[i] - '0'));
		i++;
	}
	return (integer);
}
/**
 * _env - prints the current environment
 *
 * @args: array of arguments
 */
void _env(char **args __attribute__ ((unused)))
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		puts(environ[i]);
		puts("\n");
	}
}
/**
 * _mysetenv - Intialize a new env
 *
 * @args: array of entered words
 */
void _mysetenv(char **args)
{
	int i, j, k;

	if (!args[1] || !args[2])
	{
		perror(_mygetenv("_"));
		return;
	}

	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (args[1][j] == environ[i][j])
		{
			while (args[1][j])
			{
				if (args[1][j] != environ[i][j])
					break;

				j++;
			}
			if (args[1][j] == '\0')
			{
				k = 0;
				while (args[2][k])
				{
					environ[i][j + 1 + k] = args[2][k];
					k++;
				}
				environ[i][j + 1 + k] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{
		environ[i] = concat_all(args[1], "=", args[2]);
		environ[i + 1] = '\0';
	}
}
/**
 * _myunsetenv - Remove an env var
 *
 * @args: array of entered words
 */
void _myunsetenv(char **args)
{
	int i, j;

	if (!args[1])
	{
		perror(_mygetenv("_"));
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (args[1][j] == environ[i][j])
		{
			while (args[1][j])
			{
				if (args[1][j] != environ[i][j])
					break;

				j++;
			}
			if (args[1][j] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}

