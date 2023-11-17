#include "main.h"

/**
 * prompt - prompts user for input
 * Return: string read from cli
 */
void prompt(void)
{
	ssize_t bytes;
	char *prompt = "$ ";

	if (isatty(0))
	{
		bytes = write(STDOUT_FILENO, prompt, 2);
		if (bytes == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
}
