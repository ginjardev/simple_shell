#include "main.h"

/**
 * prompt - prompts user
 *
 * Return: string read from cli
 */
char *prompt(void)
{
	char *buffer = NULL;
	size_t size;
	int count = 1;
	char *prompt = "(^_*) ";

	if (isatty(0))
	{
		write(1, prompt, 6);
	}
	count = getline(&buffer, &size, stdin);

	if (count == -1 || count == 0)
	{
		free(buffer);
		free(prompt);
		return (NULL);
	}

	if (count > 1 && buffer[count - 1] == '\n')
		buffer[count - 1] = '\0';
	free(prompt);

	return (buffer);
}

