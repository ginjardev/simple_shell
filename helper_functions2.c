#include "main.h"

/**
 * _getenv - gets value of env
 * @name: variable name
 *
 * Return: pointer to env value
 */
char *_getenv(const char *name, char **env)
{
	char *token, *dup, *str = "(null)";
	int i = 0;

	while (env[i])
	{
		/* duplicate env string */
		dup = _strdup(env[i]);

		/* tokenise dup string */
		token = strtok(dup, "=");

		/* compare name to token & return match */
		if (_strcmp(name, token) == 0)
		{
			token = strtok(NULL, "=");

			return (token);
		}
		i++;
	}

	return (str);
}
