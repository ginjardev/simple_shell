#include "main.h"

/**
 * main - starts simple shell
 * @ac: argument count
 * @av: argument vector
 * @env: environment variable
 * Return: 0 if successful
 */
int main(__attribute__((unused)) int ac, char **av, char **env)
{
	char *input, *duplicate, *command;
	char **splits;
	int status;
	pid_t pid;

	while (1)
	{
		input = prompt();
		duplicate = strdup(input);
		splits = split_str(duplicate);

		pid = fork();

		if (pid == -1)
			perror("Error");
		else if (pid == 0)
		{
			command = get_addy(splits[0]);

			if (execve(command, splits, env) == -1)
			{
				perror(av[0]);
			}
		}
		else
		{
			wait(&status);
		}

	}

	return (0);
}

