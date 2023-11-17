#include "main.h"

/**
 * space_check - will check if there are spaces in string
 * @str: string to be checked.
 * Return: true or false.
 */

int space_check(const char *str)
{
	int is_space = 1;

	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\v' &&
			*str != '\f' && *str != '\r')
		{
			is_space = 0;
			break;
		}
		str++;
	}
	return (is_space);
}

/**
 * itoa - convert integer to string.
 * @num: the integer to ocnvert.
 * Return: a string.
 */
char *itoa(int num)
{
	int temp_num = num, no_dig = (num == 0) ? 1 : ((num < 0) ? 2 : 1);

	while (temp_num /= 10)
		no_dig++;

	char *str = malloc(no_dig + 1);

	if (!str)
		return (NULL);

	str[no_dig] = '\0';
	temp_num = (num < 0) ? -num : num;

	while (no_dig-- > (num < 0))
	{
		str[no_dig] = temp_num % 10 + '0';
		temp_num /= 10;
	}

	if (num < 0)
		str[0] = '-';

	return (str);
}


/**
 * _atoi - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}


/**
 * _getenv - gets value of env
 * @name: variable name
 *
 * Return: pointer to env value
 */
char *_getenv(char *name)
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
	char *path, *path_dup, *token, *comm_path = NULL;
	int comm_length, dir_length;
	struct stat st;

	path = _getenv("PATH");

	if (path)
	{
		path_dup = _strdup(path);
		if (access(command, X_OK) == 0)
		{
			free(path_dup);
			return (command);
		}
		comm_length = _strlen(command);
		token = strtok(path_dup, ":");
		while (token)
		{
			dir_length = _strlen(token);
			comm_path = malloc(comm_length + dir_length + 2);
			_strcpy(comm_path, token);
			strcat(comm_path, "/");
			strcat(comm_path, command);
			/*_strcat(comm_path, "\0");*/
			if (stat(comm_path, &st) == 0)
			{
				free(path_dup);
				return (comm_path);
			}
			free(comm_path);
			token = strtok(NULL, ":");
		}
		free(path_dup);
	}
	else if (path == NULL || path_dup == NULL)
	{
		free(path_dup);
		return (NULL);
	}
return (NULL);
}

/*
 * REMOVED
 * exit_sh - exits shell
 * Return: 0
 */

