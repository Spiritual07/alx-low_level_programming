#include "main.h"

/**
 * _strpbrk -  function that searches a string for any of a set of bytes.
 * @s: input string
 * @accept: input string
 * Return: pointer to the byte in s that matches one of
 * the bytes in accept, or NULL if no such byte is found
 */

char *_strpbrk(char *s, char *accept)
{
	int x, y;

	/* loop through the characters in s */
	for (x = 0; s[x] != '\0'; x++)
	{
		/* for each character in s, loop through characters in accept */
		for (y = 0; accept[y] != '\0'; y++)
		{
			/* compare characters in s and accept */
			if (s[x] == accept[y])
			{
				return (&s[x]); /* return pointer to the matched character in s */
			}
		}
	}
	return ('\0'); /* return NULL if no match is found */
}
