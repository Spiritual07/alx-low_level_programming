#include "main.h"

/**
 * print_last_digit - function that prints the last digit of a number.
 * @n: number to check the last digit
 * Return: last digit of n.
 */

int print_last_digit(int n)
{

	int ld; /* declare variable for last digit */

	ld = n % 10; /* get last digit by taking modulo of 10 */

	/* to get last digit first get absolue value */
	if (ld < 0)
	{
		ld = -ld;
	}

	_putchar(ld + '0');

	return (n);
}
