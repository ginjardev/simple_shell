#ifndef _MAIN_H_
#define _MAIN_H_

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <signal.h>

/**
 * struct builtin - struct of commands & function pointers
 * @command: user command
 * @func: function pointer
 */
typedef struct builtin
{
	char *command;
	int (*func)();
} Builtin;

extern char **environ;

int _env(void);
int (*get_builtin(char *str))(char **av);
int exec_all(char *command, char **av);
int exec_command(char *command, char **av);
int exit_sh(void);
char **split_str(char *str);
char *prompt(void);
size_t _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *src);
int _strcmp(char *s1, char *s2);
char *_getenv(char *name);
char *get_addy(char *command);
int cd_dir(char **av);
#endif

