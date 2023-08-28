#include "main.h"

/**
 * _memcpy -  function that copies memory area.
 * @dest: location string to copy to
 * @src: location to copy from
 * Return: pointer to dest.
 * @n: number of bytes
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *p = dest;
	unsigned int x;

	for (x = 0; x < n; x++)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (p);
}
