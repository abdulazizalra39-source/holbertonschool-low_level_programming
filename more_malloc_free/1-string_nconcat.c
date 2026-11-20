#include "main.h"

/**
 * string_nconcat - Concatenates s1 with the first n bytes of s2
 * @s1: The first string
 * @s2: The second string
 * @n: The maximum number of bytes of s2 to use
 *
 * Return: A pointer to the new string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
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
	if (n > len2)
		n = len2;
	res = malloc(sizeof(char) * (len1 + n + 1));
	if (res == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		res[i] = s1[i];
	for (j = 0; j < n; j++)
		res[i + j] = s2[j];
	res[i + j] = '\0';
	return (res);
}
