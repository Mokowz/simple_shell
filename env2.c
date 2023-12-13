#include "shell.h"

/**
 * _setenv - initialize new env variable
 * @info: Struct
 * @var: Variable property
 * @val: String var value
 * Return: 0
 */
int _setenv(info_t *info, char *var, char *val)
{
	char *buffer = NULL;
	list_t *node;
	char *poi;

	if (!var || !val)
		return (1);
	buffer = malloc(_strlen(var) + _strlen(val) + 2);
	if (!buffer)
		return (1);
	_strcpy(buffer, var);
	_strcat(buffer, "=");
	_strcat(buffer, val);

	node = info->env;
	while (node)
	{
		poi = starts_with(node->str, var);
		if (poi && *poi == '=')
		{
			free(node->str);
			node->str = buffer;
			info->environ_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buffer, 0);
	free(buffer);
	info->environ_changed = 1;
	return (0);
}

/**
 * _unsetenv - remove an environment variable
 * @info:Struct
 * @car: String var
 * Return 1, 0
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t index = 0;
	char *p;

	if (!node || !var)
		return (0);
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->environ_changed = delete_node_at_index(&(info->env), index);
			node = info->env;
			continue;
		}
		node = node->next;
		index++;
	}
	return (info->environ_changed);
}
