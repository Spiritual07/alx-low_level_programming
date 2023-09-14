#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - function that returns the sum of all its parameters.
 * @n: numbers of parameter
 * Return: 0, if n equal to 0, or sum if n is not 0
 */

int sum_them_all(const unsigned int n, ...)
{
	unsigned int sum = 0, x, next_num;
	va_list args;

	va_start(args, n);
	if (n == 0)
	{
		return (0);
	}
	for (x = 0; x < n; x++)
	{
		next_num = va_arg(args, unsigned int);
		sum += next_num;
	}
	return (sum);
}
