#include "main.h"

/**
 * cap_string - Capitalizes all words of a string
 * @s: The string to modify
 *
 * Return: A pointer to s
 */
char *cap_string(char *s)
{
	int i, j, cap;
	char sep[] = " \t\n,;.!?\"(){}";

	cap = 1;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (cap && s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		cap = 0;
		for (j = 0; sep[j] != '\0'; j++)
		{
			if (s[i] == sep[j])
				cap = 1;
		}
	}
	return (s);
}
