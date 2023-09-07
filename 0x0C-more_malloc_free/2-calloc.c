#include "main.h"
#include <stdlib.h>

/**
 * _calloc -  function that allocates memory for an array, using malloc.
 * @nmemb: array element
 * @size: size of element
 * Return: pointer to allocated memory
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	int *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = calloc(nmemb, size);
	return (ptr);
}
