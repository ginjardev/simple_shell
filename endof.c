#include "main.h"

/**
 * endof - terminates the shell.
 * @stream: tokenized stream
 * @str: untokenized stream.
 * @av: command arguments.
 * @ac: argumaents count.
 * @status: exit status.
 * Return: exit status.
 */
int endof(char **stream, char *str, char **av, int ac, int status)
{
	char *acstr = itoa(ac);
	char *error = "Invalid number";

	if (stream[1] != NULL)
	{
		status = atoi(stream[1]);

		if (status == -1)
		{
			fprintf(stderr, "%s%s%s%s%s%s%s%s%s%s", av[0], ":", acstr, ":",
				stream[0], ":", error, ":", stream[1], "\n");
			free(acstr);
			return (2);
		}
		else
		{
			free(acstr);
			mem_free(stream, str);
			exit(status);
		}
	}
	else
	{
		free(acstr);
		/* mem_free(stream, str); */
		exit(status);
	}
}
