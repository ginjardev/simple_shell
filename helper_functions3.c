#include "main.h"

/**
 * exec_command - executes commands
 * @command: user command
 * @av: command line arguments
 *
 * Return: 1 on success
 */
int exec_command(char *command, char **av)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
		perror("Error");
	else if (pid == 0)
	{
		command = get_addy(command);

		if (execve(command, av, environ) == -1)
			perror(av[0]);
	}
	else
		wait(&status);

	return (1);
}

/**
 * get_builtin - executes built-in commands
 * @str: function pointer argument
 *
 * Return: function pointer
 */
int (*get_builtin(char *str))(char **av)
{
	int counter = 0;

	Builtin arr[] = {
		{"exit", exit_sh},
		{"cd", cd_dir},
		{"env", _env},
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

/**
 * exec_all - executes user commands
 * @command: user command
 * @av: argument vector
 *
 * Return: 0 on success
 */

int exec_all(char *command, char **av)
{
	int (*function)(char **av);

	if (av[0] == NULL)
		return (1);

	function = get_builtin(av[0]);

	if (function != NULL)
		return (function(av));
	else
		return (exec_command(command, av));
}

/**
 * _env - prints the evironment variables
 *
 * Return: 1 on success.
 */
int _env(void)
{
	int row, col;

	for (row = 0; environ[row]; row++)
	{

		for (col = 0; environ[row][col]; col++)
			;

		write(STDOUT_FILENO, environ[row], col);
		write(STDOUT_FILENO, "\n", 1);
	}

	return (1);
}

/**
 * cd_dir - changes current directory
 * @av: arguments list
 *
 * Return: 1 on success
 */
int cd_dir(char **av)
{
	char buffer[4096];

	if (av[1] == NULL)
	{
		/*Change directory to home directory*/
		const char *home_dir = _getenv("HOME");

		if (home_dir == NULL)
		{
			perror("HOME not set");
			return (1);
		}

		if (chdir(home_dir) == 0)
		{
			if (getcwd(buffer, 4096) == NULL)
				perror("Can't print dir");
		}
		else
			perror("chdir error");
	}
	else
	{
		if (chdir(av[1]) == 0)
		{
			if (getcwd(buffer, 4096) == NULL)
				perror("Can't print dir");
		}
		else
			perror("chdir error");
	}
	return (1);
}

