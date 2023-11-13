#include "main.h"

/**
 * _getenv - gets value of env
 * @name: variable name
 *
 * Return: pointer to env value
 */
char *_getenv(const char *name)
{
	char *token, *dup, *str = "(null)";
	int i = 0;

	while (environ[i])
	{
		/* duplicate env string */
		dup = _strdup(environ[i]);

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

/**
 * get_addy - finds fullpath for short commands
 * @command: user command input
 * Return: fullpath of command
 */
char *get_addy(char *command)
{
	char *path, *path_dup, *token, *comm_path;
	int comm_length, dir_length;
	struct stat st;

	path = _getenv("PATH");

	if (path)
	{
		path_dup = strdup(path);
		comm_length = strlen(command);

		token = strtok(path_dup, ":");
		while (token)
		{
			dir_length = strlen(token);
			comm_path = malloc(comm_length + dir_length + 2);
			strcpy(comm_path, token);
			strcat(comm_path, "/");
			strcat(comm_path, command);
			strcat(comm_path, "\0");

			if (stat(comm_path, &st) == 0)
			{
				free(path_dup);
				return (comm_path);
			}
			else
			{
				free(comm_path);
				token = strtok(NULL, ":");
			}
		}

		free(path_dup);
		if (stat(command, &st) == 0)
			return (command);

		return (NULL);
	}
	return (NULL);
}

