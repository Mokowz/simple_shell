#include "shell.h"

/**
 * **_strtok - splits a string into words
 * @str: String
 * @delim: Delimeter
 * Return: pointer to the arrat of strings
 */
char **_strtok(char *str, char *delim)
{
	int i, j, m, n, words = 0;
	char **new_str;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!delim)
		delim = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], delim) && (is_delim(str[i + 1], delim) || !str[i + 1]))
			words += 1;
	if (words == 0)
		return (NULL);

	new_str = malloc(sizeof(char *) * (words + 1));

	if (new_str == NULL)
		return (NULL);
	for (i = 0, j = 0; j < words; j++)
	{
		while (is_delim(str[i], delim))
			i++;
		m = 0;
		while (!is_delim(str[i + m], delim) && str[i + m])
			m++;
		new_str[j] = malloc(sizeof(char) * (m + 1));
		if (new_str[j] == NULL)
		{
			for (m = 0; m < j; m++)
				free(new_str[m]);

			free(new_str);
			return (NULL);
		}
		for (n = 0; n < m; n++)
			new_str[j][n] = str[i++];
		new_str[j][n] = 0;
	}
	new_str[j] = NULL;
	return (new_str);
}
