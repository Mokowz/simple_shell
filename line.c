#include "shell.h"
/**
 * split_string - splits a string and make it an array of point
 *
 * @str: the string to split
 * @delim: the delimeter
 * Return: array of pointers to words
 */
char **split_string(char *str, const char *delim)
{
	int i, j;
	char **array;
	char *token;
	char *copy;

	copy = malloc(_mystrlen(str) + 1);
	if (copy == NULL)
	{
		perror(_mygetenv("_"));
		return (NULL);
	}

	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';

	token = strtok(copy, delim);
	array = malloc((sizeof(char *) * 2));
	array[0] = strdup(token);

	i = 1;
	j = 3;
	while (token)
	{
		token = strtok(NULL, delim);
		array = realloc(array, (sizeof(char *) * (j - 1)), (sizeof(char *) * j));
		array[i] = strdup(token);
		i++;
		j++;
	}
	free(copy);
	return (array);
}
/**
 * _execute - executes a command
 *
 * @args: array of arguments
 */
void _execute(char **args)
{
	int i, stat;

	if (!args || !args[0])
		return;

	i = fork();
	if (i == -1)
	{
		perror(_mygetenv("_"));
	}

	if (i == 0)
	{
		execve(args[0], args, environ);
		perror(args[0]);
		exit(EXIT_FAILURE);
	}

	wait(&stat);
}
/**
 * realloc - Reallocates memory block
 *
 * @ptr: previous pointer
 * @old_size: old sixe of the previous pointer
 * @new_size: new size for our pointer
 * Return: new resized pointer
 */
void *realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;
	char *old;

	unsigned int i;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);
	old = ptr;
	if (new == NULL)
		return (NULL);

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			new[i] = old[i];
		free(ptr);
		for (i = old_size; i < new_size; i++)
			new[i] = '\0';
	}

	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			new[i] = old[i];
		free(ptr);
	}

	return (new);
}
/**
 * freeargs - frees the array of pointers
 *
 * @args: array of pointers
 */
void freeargs(char **args)
{
	int i;

	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
}
