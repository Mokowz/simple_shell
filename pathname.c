#include "shell.h"

/**
 * _mygetenv - get value of global variable
 * @str: string name
 * Return: String of value
 */
char *_mygetenv(const char *str)
{
	int i, m;
	char *name;

	if (str == NULL)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		m = 0;
		if (str[m] == environ[i][m])
		{
			while (str[m])
			{
				if (str[m] != environ[i][m])
					break;
				m++;
			}
			if (str[m] == '\0')
			{
				name = (environ[i] + m + 1);
				return (name);
			}
		}
	}

	return (0);
}

/**
 * linkpathname - create a linked list of path
 * @path: Path value
 * Return: path to the linked lsit
 */
list_pathname *linkpathname(char *path)
{
	char *newtok;
	char *npath = strdup(path);
	list_pathname *temp = '\0';

	newtok = strtok(npath, ":");
	while (newtok != NULL)
	{
		temp = add_node_to_end(&temp, newtok);
		newtok = strtok(NULL, ":");
	}
	return (temp);
}

/**
 * add_node_to_end - add new node to end
 * @head: Pointer of hed
 * @str: String
 * Return: address of new node
 */
list_pathname *add_node_to_end(list_pathname **head, char *str)
{
	list_pathname *temp;
	list_pathname *rand;

	rand = malloc(sizeof(list_pathname));

	if (str == NULL || rand == NULL)
		return (NULL);
	rand->data = str;
	rand->path = '\0';
	if (*head == NULL)
	{
		*head = rand;
	}
	else
	{
		temp = *head;

		while (temp->path)
		{
			temp = temp->path;
		}
		temp->path = rand;
	}
	return (*head);
}
