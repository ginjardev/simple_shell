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
	int i, check = 1;
	char *input, *duplicate, *command;
	(void) ac;

	while (check)
	{
		input = prompt();
		if (input == NULL)
		{
			free(input);
			break;
		}
		duplicate = _strdup(input);
		av = split_str(duplicate);
		command = av[0];

		check = exec_all(command, av);
		/*free(input);
		free(duplicate);

		for (i = 0; av[i]; i++)
			free(av[i]);

		free(av); */
	}

	return (0);
}

