#include "main.h"

/**
 * _strncpy - Copies at most n bytes of a string
 * @dest: The buffer to copy to
 * @src: The string to copy
 * @n: The maximum number of bytes to copy
 *
 * Return: A pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';
	return (dest);
}
