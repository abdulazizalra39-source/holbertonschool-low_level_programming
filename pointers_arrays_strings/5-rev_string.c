#include "main.h"

/**
 * rev_string - Reverses a string in place
 * @s: The string to reverse
 */
void rev_string(char *s)
{
	int start, end;
	char tmp;

	end = 0;
	while (s[end] != '\0')
		end++;
	end--;
	for (start = 0; start < end; start++, end--)
	{
		tmp = s[start];
		s[start] = s[end];
		s[end] = tmp;
	}
}
