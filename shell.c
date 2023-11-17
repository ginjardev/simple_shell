#include "main.h"

/**
 * main - starts simple shell
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 if successful
 */
int main(int ac, char **av)
{
	int check = 1;
	char *stream = NULL;
	char **tokens, *command;
	int stat = 0;

	while (check)
	{
		prompt();
		stream = get_stream(stream, stat);

		if (space_check(stream))
		{
			free(stream);
			continue;
		}

		tokens = malloc(sizeof(char *) * 1024);
		tokens = split_str(stream);

		if (_strcmp(tokens[0], "exit") == 0)
			stat = endof(tokens, stream, av, ac, stat);
		else
			stat = exec_all(tokens, av, ac);
		ac++;
		mem_free(tokens, stream);
		/*
		* completely edited: see original
		*/
	}
	return (stat);
}

