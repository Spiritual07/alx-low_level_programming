#include "main.h"

/**
 * _strncpy - function that copies a string
 * @dest: base string
 * @src: string to copy from
 * @n: number of characters.
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;
	char *p = dest; /* pointer 'p' to remember the start of the dest string */

	/* Loop to copy characters from src to dest */
	/*  up to n characters or until src's null terminator */
	for (i = 0; i < n && *src != '\0'; i++)
	{
		*dest++ = *src++;
	}
	for (; i < n; i++)
	{
		*dest = '\0';
	}

	return (p); /* Return the starting address of the copied dest string */
}
