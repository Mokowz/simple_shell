#include "shell.h"

/**
 * _strchr - locate a character
 * @str: String
 * @c: CHaracter
 * Return: pointer to character
 */
char *_strchr(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}

	if (*str == c)
		return (str);

	return (NULL);
}

/**
 * _strncat - concatenate a str
 * @dest: string 1
 * @src: String 2
 * @n: Amount of bytes
 * Return: concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	char *s = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0' && n > 0)
	{
		*dest++ = *src++;
		n--;
	}

	*dest = '\0';

	return (s);
}

/**
 * _strncpy - copies a string
 * @dest: Destination string
 * @src: Source string
 * @n: Amount of characters to copy
 * Return: concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *s = dest;
	int i;

	for (i = 0; i < n - 1 && src[i] != '\0'; i++)
		dest[i] = src[i];

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (s);
}
