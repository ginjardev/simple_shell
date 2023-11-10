#include "main.h"

/**
 * main - starts simple shell
 * @ac: argument count
 * @av: argument vector
 * @env: environment variable
 */
int main(int ac, char **av, char **env)
{
	char *input, *token, *duplicate;
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
			if(execve(splits[0], splits, NULL) == -1)
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

