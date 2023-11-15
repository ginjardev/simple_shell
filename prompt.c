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

	while (count == 1)
	{
		write(1, prompt, 6);
		count = getline(&buffer, &size, stdin);

		if (count == -1)
		{
			free(buffer);
		}
	}
	if (count > 1 && buffer[count - 1] == '\n')
		buffer[count - 1] = '\0';

	return (buffer);
}

