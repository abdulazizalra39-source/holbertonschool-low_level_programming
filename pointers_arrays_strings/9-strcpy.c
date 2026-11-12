#include "main.h"

/**
 * _strcpy - Copies a string, including the terminating null byte
 * @dest: The buffer to copy to
 * @src: The string to copy
 *
 * Return: A pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
