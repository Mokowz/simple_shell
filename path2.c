#include "shell.h"

/**
 * which_path - finds path
 * @file: name of file
 * @head: Head of linked list
 * Return: pathname
 */
char *which_path(char *file, list_pathname *head)
{
	char *str;
	struct stat sti;

	list_pathname *temp = head;

	while (temp)
	{
		str = _concat(temp->data, "/", file);
		if (stat(str, &sti) == 0)
			return (str);
		free(str);
		temp = temp->path;
	}
	return (NULL);
}

/**
 * flist - free a list
 * @head: Pointer to list
 */
void flist(list_pathname *head)
{
	list_pathname *temp;

	while (head != NULL)
	{
		temp = head->path;
		free(head->data);
		free(head);
		head = temp;
	}
}
