#include "main.h"

/**
 * _strlen - returns the length of a string.
 * @s: input string.
 * Return: length of a string.
 */
size_t _strlen(const char *s)
{
	int count = 0;

	while (*(s + count) != '\0')
		count++;
	return (count);
}

/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte, to the
 * buffer pointed to by dest.
 * @dest: destination.
 * @src: source.
 * Return: the pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int count = 0;

	while (count >= 0)
	{
		*(dest + count) = *(src + count);
		if (*(src + count) == '\0')
			break;
		count++;
	}
	return (dest);
}

/**
 * _strdup - copies the string pointed to by src,
 * including the terminating null byte, to a
 * buffer pointed to by dest.
 * @src: source string.
 * Return: pointer to dest.
 */
char *_strdup(const char *src)
{
	int i, length = 0;
	char *dest;

	/*strlen*/
	while (src[length] != '\0')
	{
		length++;
	}

	dest = (char *)malloc(length + 1);

	if (dest == NULL)
	{
		return (NULL);
	}
	/*copy chars of src into dest*/
	for (i = 0; i <= length; i++)
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

/**
 * split_str - splits string and returns array of strings
 * @str: string parameter
 * Return: array of strings
 */
char **split_str(char *str)
{
	char *string = _strdup(str);
	char *string1 = _strdup(str);
	char *token = strtok(string, " ");
	int count = 0, i;
	char *t;
	char **arr;

	while (token != NULL)
	{
		++count;
		token = strtok(NULL, " ");
	}

	arr = malloc(sizeof(char *) * count + 1);

	t = strtok(string1, " ");

	for (i = 0; i < count; i++)
	{
		if (t != NULL)
		{
			arr[i] = malloc(sizeof(char *) * strlen(t));
			arr[i] = t;
		}

		t = strtok(NULL, " ");
	}

	return (arr);
}
