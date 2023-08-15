#include "main.h"
#include <stdio.h>

/**
 * print_to_98 - function that prints all
 * natural numbers from n to 98
 * @n: integer starting the number
 */

void print_to_98(int n)
{
	int x, y;

	if (n <= 98)
	{
		for (x = n; x <= 98; x++)
		{
			if (x != 98)
				printf("%d, ", x);
			else if (x == 98)
				printf("%d\n", x);
		}
	}
	else if (n >= 98)
	{
		for (y = n; y >= 98; y--)
		{
			if (y != 98)
				printf("%d, ", y);
			else if (y == 98)
				printf("%d\n", y);
		}
	}
}
