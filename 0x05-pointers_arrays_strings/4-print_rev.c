#include "main.h"

/**
 * print_rev - function that prints a string, in
 * reverse, followed by a new line.
 * @s: string to be printed
 */

void print_rev(char *s)
{
	int len = 0;
	int x;

	/* calculate length of string */
	while (s[len] != '\0')
	{
		len++;
	}

	/* print length of string in reverse */
	for (x = len - 1; x >= 0; x--)
	{
		_putchar(s[x]);
	}
	_putchar('\n');
}
