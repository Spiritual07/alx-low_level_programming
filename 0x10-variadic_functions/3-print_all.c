#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all -  function that prints anything.
 * @format:  a list of types of arguments passed to the function
 */

void print_all(const char * const format, ...)
{
	unsigned int x = 0, y, z = 0;
	char *str;
	va_list args;
	const char fmt[] = "cifs";

	va_start(args, format);
	while (format && format[x])
	{
		y = 0;
		while (fmt[y])
		{
			if (format[x] == fmt[y] && z)
				printf(", ");
			y++;
		}
		switch (format[x])
		{
			case 'i':
					printf("%d", va_arg(args, int)), z = 1;
					break;
			case 'c':
					printf("%c", va_arg(args, int)), z = 1;
					break;
			case 'f':
					printf("%f", va_arg(args, double)), z = 1;
					break;
			case 's':
					str = va_arg(args, char*), z = 1;
					if (str == NULL)
					{
						printf("(nil)");
						break;
					}
					printf("%s", str);
					break;
			default:
					break;
		} x++;
	}
	va_end(args), printf("\n");
}
