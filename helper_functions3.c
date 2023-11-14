#include "main.h"

/**
 * _execute - executes user commands
 * @command: user command
 *
 * Return: 0 on success
 */

int exec_builtin(char *command)
{
	int (*perform)(char *command);

	perform = get_builtin(command);

	if (perform != NULL)
		return (perform(command));
	else
		return (1);
}

/**
 * exec_builtin - executes built-in commands
 * @command: user command
 *
 * Return: 0 on success
 */
int (*get_builtin(char *str))(char *command)
{
	int counter = 0;

	Builtin arr[] = {
		{"exit", exit_sh},
		{NULL, NULL}
	};

	while (arr[counter].command != NULL)
	{
		if (_strcmp(arr[counter].command, str) == 0)
			break;
		counter++;
	}

	return (arr[counter].func);
}

