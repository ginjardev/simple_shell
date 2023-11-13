#include "main.h"

/**
 * main - starts simple shell
 * @ac: argument count
 * @av: argument vector
 * @env: environment variable
<<<<<<< HEAD
 * Return: 0
=======
 * Return: 0 if successful
>>>>>>> 7bb9d9c87a6cbbedf84df9c19c0099bd0e325151
 */
int main(int ac, char **av, char **env)
{
	char *input, *token, *duplicate, *command;
	char **splits;
	size_t size;
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

			if (execve(splits[0], splits, NULL) == -1)
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

