#include "shell.h"
/**
 * main - shell prgram
 * Return: 0
 */
int main(void)
{
	size_t total = 0;
	ssize_t len = 0;
	list_pathname *head = '\0';
	char *buffer = NULL, *val, *pathn, **argv;
	void (*f)(char **);

	signal(SIGINT, sigHandler);
	while (len != EOF)
	{
		isterm();
		len = getline(&buffer, &total, stdin);
		end_file(len, buffer);
		argv = split_string(buffer, " \n");

		if (!argv[0] || !argv)
		{
			_execute(argv);
		}
		else
		{
			val = _mygetenv("PATH");
			head = linkpathname(val);
			pathn = which_path(argv[0], head);
			f = check_builtin(argv);

			if (f)
			{
				free(buffer);
				f(argv);
			}
			else if (pathn)
			{
				free(argv[0]);
				argv[0] = pathn;
				_execute(argv);
			}
			else if (!pathn)
			{
				_execute(argv);
			}
		}
	}
	flist(head);
	freeargs(argv);
	free(buffer);
	return (0);
}
