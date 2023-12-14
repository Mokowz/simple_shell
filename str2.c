#include "shell.h"

/**
 * _strdup - return pointer to newly allocated space
 * @str: String
 * Return: Pointer to string
 */
char *_strdup(char *str)
{
	int i, j;
	char *newString;


	if (!str)
		return (NULL);
	for (j = 0; str[j] != '\0';)
		j++;
	newString = malloc(sizeof(char) * (j + 1));
	if (newString == NULL)
		return (NULL);
	for (i = 0; i < j; i++)
		newString[i] = str[i];
	newString[j] = str[j];
	return (newString);
}

/**
 * _concat - concat strings
 * @str1: Strign 1
 * @str2: String 2
 * @str3: Sttring 3
 * Return: Pointer to new stirng
 */
char *_concat(char *str1, char *str2, char *str3)
{
	char *newString;
	int len1, len2, len3;
	int i, j;

	len1 = _mystrlen(str1);
	len2 = _mystrlen(str2);
	len3 = _mystrlen(str3);

	newString = malloc(len1 + len2 + len3 + 1);
	if (newString == NULL)
		return (NULL);
	for (i = 0; str1[i]; i++)
		newString[i] = str1[i];
	j = i;
	for (i = 0; str2[i] != '\0'; i++)
		newString[i + j] = str2[i];
	j += i;

	for (i = 0; str3[i] != '\0'; i++)
		newString[j + i] = str3[i];
	j += i;
	newString[j] = '\0';

	return (newString);
}
