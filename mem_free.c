#include "main.h"

/**
 * mem_free - release memory allocated.
 * @tokens: tokenized user input.
 * @str: untokenized user input.
 */
void mem_free(char **tokens, char *str)
{
	free(str);

	int k = 0;

	while (tokens[k] != NULL)
	{
		free(tokens[k]);
		k++;
	}

	free(tokens);
}
