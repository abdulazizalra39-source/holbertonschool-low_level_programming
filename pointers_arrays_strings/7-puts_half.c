#include "main.h"

/**
 * puts_half - Prints the second half of a string, followed by a new line
 * @str: The string to print
 */
void puts_half(char *str)
{
	int len, i;

	len = 0;
	while (str[len] != '\0')
		len++;
	for (i = (len + 1) / 2; i < len; i++)
		_putchar(str[i]);
	_putchar('\n');
}
