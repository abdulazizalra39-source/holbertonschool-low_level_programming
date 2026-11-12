#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: The string to convert
 *
 * Return: The converted integer, or 0 if there is no number
 */
int _atoi(char *s)
{
	int i, sign, started, result;

	i = 0;
	sign = 1;
	started = 0;
	result = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			result = result * 10 - (s[i] - '0');
		}
		else if (started)
			break;
		else if (s[i] == '-')
			sign = -sign;
		i++;
	}
	if (sign == 1)
		result = -result;
	return (result);
}
