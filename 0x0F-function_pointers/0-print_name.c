#include "function_pointers.h"

/**
 * print_name - function that prints a name
 * @name: the name to be printed
 * @f: function pointer name.
 */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL)
	{
		return;
	}
	f(name);
}
