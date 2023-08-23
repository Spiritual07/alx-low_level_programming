#include "main.h"

/**
 * _strncat - function that concatenates two strings up to n characters.
 * @dest: Base string
 * @src: string to be append
 * @n: maximum number of characters to be taken from the src string
 * Return: point to dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int i;
	int src_len = 0;
	char *p = dest;
	char *s = src;

	/* find the length of the src string */
	while (*src)
	{
		src_len++;
		src++;
	}
	/* find the end of the dest string */
	while (*dest)
	{
		dest++;
	}
	/* limit character to be appended to src string length */
	if (n > src_len)
	{
		n = src_len;
	}
	/* src pointer is reset to point back to the start of */
	/* the src string using the previously stored pointer s. */
	src = s;

	/* append characters from src string to dest string */
	for (i = 0; i < n; i++)
	{
		*dest++ = *src++;
	}
	/* NULL terminate dest string */
	*dest = '\0';

	return (p);

}
