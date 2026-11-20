#include "main.h"

/**
 * _strdup - Returns a pointer to a newly allocated copy of a string
 * @str: The string to duplicate
 *
 * Return: A pointer to the copy, or NULL if str is NULL or it fails
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len;

	if (str == NULL)
		return (NULL);
	len = 0;
	while (str[len] != '\0')
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		dup[i] = str[i];
	return (dup);
}
