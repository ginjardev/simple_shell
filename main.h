#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

char **split_str(char *str);
char *prompt(void);
size_t _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *src);
int _strcmp(char *s1, char *s2);
char *_getenv(const char *name, char **env);

#endif
