#include "main.h"

/**
 * _strlen - Returns the length of a string
 * @s: The string to measure
 *
 * Return: The length of s
 */
int _strlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
