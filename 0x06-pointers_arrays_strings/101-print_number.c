#include "main.h"

/**
 * print_number - function that prints an integer.
 * @n: integer to be printed
 */

void print_number(int n)
{
	unsigned int num;

	/* check if number is negative */
	if (n < 0)
	{
		num = -n;
		_putchar('-'); /* print -ve sign if number is negative */
	}
	else
	{
		num = n;
	}
	/* check to see if there are more digits to print */
	if (num / 10)
	{
		print_number(num / 10); /* recursive call to print remaining digits */
	}

	_putchar('0' + (num % 10)); /* print last digit */
}
