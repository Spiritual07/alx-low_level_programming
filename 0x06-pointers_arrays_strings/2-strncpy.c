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

	/* Loop over the first 'n' characters of 'src' */
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i]; /* Copy each character from 'src' to 'dest' */
	}
	while (i < n)
	{
		dest[i] = '\0'; /* Fill the rest of 'dest' with null characters ('\0') */
		i++;
	}

	return (dest); /* return dest string */
}
