#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all -  function that prints anything.
 * @format:  a list of types of arguments passed to the function
 */

void print_all(const char * const format, ...)
{
	int x = 0;
	char *str;
	va_list args;

	va_start(args, format);
	while (format[x])
	{
		if (x > 0 && (format[x] == 'i' || format[x] == 'c' || format[x] == 'f' || format[x] == 's'))
		{
			printf(", ");
		}
		switch (format[x])
		{
			case 'i':
					printf("%d", va_arg(args, int));
					break;
			case 'c':
					printf("%c", va_arg(args, int));
					break;
			case 'f':
					printf("%f", va_arg(args, double));
					break;
			case 's':
				{
					str = va_arg(args, char*);
					if (str == NULL)
						printf("(nil)");
					printf("%s", str);
					break;
				}
			default:
					break;
		}
		x++;
	}
	va_end(args);
	printf("\n");
}
