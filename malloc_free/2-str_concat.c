#include "main.h"

/**
 * str_concat - Concatenates two strings into a newly allocated string
 * @s1: The first string
 * @s2: The second string
 *
 * Return: A pointer to the new string, or NULL if it fails
 */
char *str_concat(char *s1, char *s2)
{
	char *res;
	unsigned int len1, len2, i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	len1 = 0;
	while (s1[len1] != '\0')
		len1++;
	len2 = 0;
	while (s2[len2] != '\0')
		len2++;
	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (res == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		res[i] = s1[i];
	for (j = 0; j <= len2; j++)
		res[i + j] = s2[j];
	return (res);
}
