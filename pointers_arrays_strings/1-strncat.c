#include "main.h"

/**
 * _strncat - Concatenates at most n bytes of src to dest
 * @dest: The string to append to
 * @src: The string to append
 * @n: The maximum number of bytes to use from src
 *
 * Return: A pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	for (j = 0; j < n && src[j] != '\0'; j++)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}
