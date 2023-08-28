#include "main.h"

/**
 * _memset - function that fills memory with a constant byte.
 * @s: memory area pointed to by pointer
 * @b: constant byte
 * @n: number of bytes
 * Return: pointer to s.
 */

char *_memset(char *s, char b, unsigned int n)
{
	char *ptS = s; /* Pointer to the starting memory address */
	unsigned int x;

	/* loop through each byte */
	for (x = 0; x < n; x++)
	{
		*ptS = b; /* Fill memory with b by assigning it to ptS */

		ptS++; /* increment to move to the next memory location */
	}

	return (ptS);
}
