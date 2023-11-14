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
