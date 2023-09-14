#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - function that prints numbers, followed by a new line.
 * @separator: string to be printed between numbers
 * @n:  number of integers passed to the function
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int x;
	int next_num;
	va_list args;

	va_start(args, n);

	for (x = 0; x < n; x++)
	{
		next_num = va_arg(args, int);
		printf("%d", next_num);
		if (separator != NULL && x < n - 1)
		{
			printf("%s", separator);
		}
	}
	va_end(args);
	printf("\n");
}
