#include "shell.h"

/**
 * buffer_input - buffers chained commands
 * @info: parameter struct
 * @buffer: address of buffer
 * @length: address of length variable
 *
 * Return: bytes read
 */
ssize_t buffer_input(info_t *info, char **buffer, size_t *length)
{
	ssize_t bytesRead = 0;
	size_t currentLength = 0;

	if (!*length) /* if nothing left in the buffer, fill it */
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		bytesRead = getline(buffer, &currentLength, stdin);
#else
		bytesRead = _getline(info, buffer, &currentLength);
#endif
		if (bytesRead > 0)
		{
			if ((*buffer)[bytesRead - 1] == '\n')
			{
				(*buffer)[bytesRead - 1] = '\0'; /* remove trailing newline */
				bytesRead--;
			}
			info->linecount_flag = 1;
			remove_comments(*buffer);
			build_history_list(info, *buffer, info->histcount++);
			/* if (_strchr(*buffer, ';')) is this a command chain? */
			{
				*length = bytesRead;
				info->cmd_buffer = buffer;
			}
		}
	}
	return (bytesRead);
}

/**
 * get_input_line - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input_line(info_t *info)
{
	static char *commandBuffer; /* the ';' command chain buffer */
	static size_t bufferIndex, j, bufferLength;
	ssize_t bytesRead = 0;
	char **currentBuffer = &(info->argument), *currentPosition;

	_putchar(BUF_FLUSH);
	bytesRead = buffer_input(info, &commandBuffer, &bufferLength);
	if (bytesRead == -1) /* EOF */
		return (-1);
	if (bufferLength) /* we have commands left in the chain buffer */
	{
		j = bufferIndex; /* initialize new iterator to current buffer position */
		currentPosition = commandBuffer + bufferIndex; /* get pointer for return */
		check_chain(info, commandBuffer, &j, bufferIndex, bufferLength);

		while (j < bufferLength) /* iterate to semicolon or end */
		{
			if (is_chain(info, commandBuffer, &j))
				break;
			j++;
		}

		bufferIndex = j + 1; /* increment past nulled ';'' */
		if (bufferIndex >= bufferLength) /* reached end of buffer? */
		{
			bufferIndex = bufferLength = 0; /* reset position and length */
			info->cmd_buffer_type = 0;
		}
		*currentBuffer = currentPosition;
		return (_strlen(currentPosition)); /* return length of current command */
	}
	*currentBuffer = commandBuffer;
	return (bytesRead); /* return length of buffer from _getline() */
}

/**
 * read_buffer - reads a buffer
 * @info: parameter struct
 * @buffer: buffer
 * @index: size
 *
 * Return: bytesRead
 */
ssize_t read_buffer(info_t *info, char *buffer, size_t *index)
{
	ssize_t bytesRead = 0;

	if (*index)
		return (0);

	bytesRead = read(info->readfd, buffer, 1024);
	if (bytesRead >= 0)
		*index = bytesRead;

	return (bytesRead);
}

/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @pointer: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated pointer buffer if not NULL
 *
 * Return: size
 */
int _getline(info_t *info, char **pointer, size_t *length)
{
	static char buffer[1024];
	static size_t bufferIndex, bufferLength;
	size_t k;
	ssize_t bytesRead = 0, size = 0;
	char *currentPointer = NULL, *newPointer = NULL, *c;
	int i;

	currentPointer = *pointer;
	if (currentPointer && length)
		size = *length;

	if (bufferIndex == bufferLength)
	{
		bufferIndex = bufferLength = 0;
	}

	bytesRead = read_buffer(info, buffer, &bufferLength);
	if (bytesRead == -1 || (bytesRead == 0 && bufferLength == 0))
		return (-1);
	c = _strchr(buffer + bufferIndex, '\n');
	k = c ? 1 + (unsigned int)(c - buffer) : bufferLength;

	newPointer = _realloc(currentPointer, size, size ? size + k : k + 1);
	if (!newPointer) /* MALLOC FAILURE! */
		return (currentPointer ? free(currentPointer), -1 : -1);

	if (size)
		_strncat(newPointer, buffer + i, k - i);
	else
		_strncpy(newPointer, buffer + i, k - i + 1);

	size += k - i;
	i = k;
	currentPointer = newPointer;

	if (bufferLength)
		bufferLength = size;
	*pointer = currentPointer;
	return (size);
}

/**
 * sigintHandler - block ctrl c
 * @signum: signal number
 */
void sigintHandler(__attribute__((unused))int signum)
{
	_puts("\n");
	_puts("$ ");
	_putchar(-1);
}
