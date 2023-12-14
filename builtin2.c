#include "shell.h"
/**
 * check_builtin - checks if the command is a builtin
 *
 *@args: array of arguments
 * Return: pointer to function that takes args and returns void
 */
void(*check_builtin(char **args))(char **args)
{
	int i, j;
	_mybuild BUILTINS[] = {
		{"exit", custom_exit},
		{"env", _env},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{NULL, NULL}
	};

	for (i = 0; BUILTINS[i].name; i++)
	{
		j = 0;
		if (BUILTINS[i].name[j] == args[0][j])
		{
			while (args[0][j])
			{
				if (BUILTINS[i].name[j] != args[0][j])
					break;
				j++;
			}
			if (!args[0][j])
				return (BUILTINS[i].func);
		}
	}
	return (NULL);
}
