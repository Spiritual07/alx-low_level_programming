#include "main.h"

/**
 * print_number - function that prints an integer.
 * @n: integer to be print
 */

void print_number(int n)
{
	unsigned int n1;

	if (n < 0) /* Check if the input number is negative */
	{
		n1 = -n; /* Take the absolute value of n */
		_putchar('-');
	}
	else
	{
		n1 = n;
	}
/* Recursively call print_number to print digits from left to right */
	if (n1 / 10)
	{
		print_number(n1 / 10); /* Recursive call with n1 divided by 10 */
	}

	_putchar((n1 % 10) + '0'); /* Print the digit by converting to ASCII */
}
