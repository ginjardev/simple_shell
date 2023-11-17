#include "main.h"

/**
 * get_stream - get user input.
 * @buffer: the buffer to store the string.
 * @status: current status.
 * Return: user input string.
 */
char *get_stream(char *buffer, int status)
{
	size_t size = 0;
	ssize_t stream;

	if (buffer == NULL)
	{
		buffer = malloc(sizeof(char));
		if (buffer == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
	}

	stream = getline(&buffer, &size, stdin);

	if (stream == -1)
	{
		if (feof(stdin))
		{
			free(buffer);
			exit(status);
		}
		else
		{
			perror("Error reading input");
			exit(EXIT_FAILURE);
		}
	}

	if (buffer[stream - 1] == '\n')
	{
		buffer[stream - 1] = '\0';
	}

	return (buffer);
}
