#include "shell.h"

/**
 * build_hist_list - adds history to linked list
 * @info: Structure
 * @buffer: buffer
 * @line_count: History linecount
 * Return: 0
 */
int build_hist_list(info_t *info, char *buffer, int line_count)
{
	list_t *node = info->hist;

	add_node_end(&node, buffer, line_count);
	if(!info->hist)
		info->hist = node;
	return (0);
}
