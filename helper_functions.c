#include "main.h"

/**
 * _strdup - copies the string pointed to by src,
 * including the terminating null byte, to a
 * buffer pointed to by dest.
 * @src: source string.
 * Return: pointer to dest.
 */
char *_strdup(const char *src)
{
	int length = 0;

	/*strlen*/
	while (src[length] != '\0')
	{
		length++;
	}

	char *dest = (char *)malloc(length + 1);

	if (dest == NULL)
	{
		return (NULL);
	}
	/*copy chars of src into dest*/
	for (int i = 0; i <= length; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string.
 * @s2: second string.
 * Return: 0 if s1 and s2 are equals,
 * another number if not.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, res = 0;

	while (res == 0)
	{
		if ((*(s1 + i) == '\0') && (*(s2 + i) == '\0'))
			break;
		res = *(s1 + i) - *(s2 + i);
		i++;
	}

	return (res);
}
