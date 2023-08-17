#include "main.h"

/**
 * print_line - function that draws a straight
 * line in the terminal.
 * @n: the number of times the character _ should be printed
 */

void print_line(int n)
{
	int a;

	if (n > 0)
	{
		for (a = 0; a < n; a++)
		{
			_putchar('_');
		}
		_putchar('\n');
	}
	else
		_putchar('\n');
}
