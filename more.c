#include "shell.h"

/**
 * is_chain: is current character a chain
 * @info: struct
 * @buffer: Character buffer
 * @posi: Address of current posi
 * Return: 1, 0
 */
int is_chain(info_t *info, char *buffer, size_t *posi)
{
	size_t j = *posi;
	char current = buffer[j];

	if ((current == '|' || current == '&') && buffer[j + 1] == current)
	{
		buffer[j] = '\0';
		j++;
		info->cmd_buffer_type = (current == '|') ? 1 : 2;
	}
	else if (current == ';')
	{
		buffer[j] = '\0';
		info->cmd_buffer_type = 3;
	}
	else
	{
		return (0);
	}
	*posi = j;
	return (1);
}

/**
 * check_chain - is chain based on last status
 * @info: struct
 * @buffer: Character buffer
 * @posi: Address of current posi
 * @i: starting posi
 * @len: Length
 */
void check_chain(info_t *info, char *buffer, size_t *posi, size_t i, size_t len)
{
	size_t j = *posi;

	if (info->cmd_buffer_type == 2 && info->status)
	{
		buffer[i] = '\0';
		j = len;
	}
	if (info->cmd_buffer_type == 1 && !info->status)
	{
		buffer[i] = '\0';
		j = len;
	}

	*posi = j;
}
