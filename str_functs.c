#include "shell.h"

/**
 * _strlen - find length of string
 * @str: String
 * Return: length
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}

/**
 * _strcmp - compares two strings
 * @str1: String 1
 * @str2: String 2
 * Return: integer
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1 += 1;
		str2 += 1;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * starts_with - checks if words are in string
 * @str: whole strnig
 * @small: Substring
 * Return: address of character
 */
char *starts_with(const char *str, const char *small)
{
	while (*small)
	{
		if (*small++ != *str++)
			return (NULL);
	}
	return ((char *)str);
}

/**
 * _strcat - concatenates 2 strings
 * @dest: Destination
 * @src: Source
 * Return: pointer to destination
 */
char *_strcat(char *dest, char *src)
{
	char *new = dest;

	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;
	*dest = *src;

	return (new);
}

/**
 * _putchar - write character c to stdout
 * @c: Character
 * Return: 1 or -1
 */
int _putchar(char c)
{
	static int i;
	static char buffer[1024];

	if (c == -1 || i >= 1024)
	{
		write(1, buffer, i);
		i = 0;
	}

	if (c != -1)
		buffer[i++] = c;

	return (1);
}
