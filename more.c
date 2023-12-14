#include "shell.h"

/**
 * sigHandler - check if c c is pressed
 * @num: int
 */
void sigHandler(int num)
{
	if (num == SIGINT)
	{
		_puts("\n$ ");
	}
}

/**
 * end_file - handle EOF
 * @len: Return of getline
 * @buffer: Buffer
 */
void end_file(int len, char *buffer)
{
	(void)buffer;

	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buffer);
		}
		exit(0);
	}
}

/**
 * isterm - is it terminal
 */
void isterm(void)
{
	if (isatty(STDIN_FILENO))
		_puts("$ ");
}
