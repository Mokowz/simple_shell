#include "shell.h"
/**
 * _realloc - reallocates a block of memory
 * @ptr: Pointer
 * @old_size: size of previous block
 * @new_size: size of new block
 * Return: pointer to old block mem
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *newPtr;
	size_t i, copy_size;

	if (!ptr)
		return (malloc(new_size));

	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);
	newPtr = malloc(new_size);
	if (!newPtr)
		return (NULL);
	copy_size = old_size < new_size ? old_size : new_size;
	for (i = 0; i < copy_size; i++)
		((char *)newPtr)[i] = ((char *)ptr)[i];
	free(ptr);

	return (newPtr);
}

/**
 * ffree - free a string
 * @str: string of strings
 */
void ffree(char **str)
{
	char **b = str;

	if (!str || !*str)
		return;
	while (*str)
	{
		free(*str);
		str++;
	}

	free(b);
}

/**
 * _memset - fill a memory
 * @str: Pointer to mem area
 * @fill: Byte to fill
 * @n: Amount of bytes
 * Return: poitner to memoty area
 */
char *_memset(char *str, char fill, unsigned int n)
{
	unsigned int j;

	for (j = 0; j < n; j++)
		str[j] = fill;

	return (str);
}

