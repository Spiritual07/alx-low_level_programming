#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked -  function that allocates memory using malloc
 * @b: input data
 * Return: pointer to allocated memory, or if malloc fails, the malloc_checked
 * function should cause normal process termination with a status value of 98
 */

void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);

	if (ptr == NULL)
	{
		exit(98);
	}
	
	return (ptr);
}
