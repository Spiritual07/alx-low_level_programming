#include "main.h"

/**
 * puts_half - function that prints half of a string,
 * followed by a new line.
 * @str: string to print half
 */

void puts_half(char *str)
{
	int len = 0;
	int x, n;

	/* calculate length of string */
	while (str[len] != '\0')
		len++;

	if (len % 2 == 0)
	{
		n = len / 2;
	}
	else
	{
		n = (len + 1) / 2;
	}
	for (x = n; x < len; x++)
	{
		_putchar(str[x]);
	}
	_putchar('\n');

}
