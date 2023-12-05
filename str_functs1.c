#include "shell.h"

/**
 * _puts - print a string
 * @str: String
 */
void _puts(char *str)
{
	int i = 0;

	if (str == NULL)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _strcpy - copies string
 * @dest: Destination
 * @src: Source
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (src == 0 || dest == src)
		return (dest);

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - duplicates string
 * @str: String
 * Return: Pointer to string
 */
char *_strdup(const char *str)
{
	int i = 0;
	char *new;

	if (!str)
		return (NULL);
	while (*str++)
		i++;
	new = malloc(sizeof(char) + (i + 1));

	if (new == NULL)
		return (NULL);

	for (i++; i--;)
		new[i] = *--str;

	return (new);
}
