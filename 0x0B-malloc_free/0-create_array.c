#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * *create_array -  function that creates an array of chars,
 * and initializes it with a specific char.
 * @size: size of the array
 * @c: array to be created
 * Return: pointer to the array of NULL if fail
 */

char *create_array(unsigned int size, char c)
{
	unsigned int x;
	char *p;

	if (size == 0)
	{
		return (NULL);
	}

	p = malloc(sizeof(char) * size);

	if (p == NULL)
	{
		return (NULL);
	}
	for (x = 0; x < size; x++)
	{
		p[x] = c;
	}
	return (p);
}
