#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring
 * @s: The string to check
 * @accept: The accepted bytes
 *
 * Return: The number of bytes in the initial segment of s made of accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count;
	int i, j, found;

	count = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		found = 0;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break;
			}
		}
		if (!found)
			break;
		count++;
	}
	return (count);
}
