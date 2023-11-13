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

	while (count == 1)
	{
		printf("%s", "0xShell$ ");
		count = getline(&buffer, &size, stdin);

		if (count == -1)
		{
			free(buffer);
			break;
		}
	}
	if (count > 1 && buffer[count - 1] == '\n')
		buffer[count - 1] = '\0';

	return (buffer);
}

