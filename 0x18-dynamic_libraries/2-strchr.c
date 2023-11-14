#include "main.h"

/**
 * _strchr - function that locates a character in a string.
 * @s: string to locate character
 * @c: character to be located
 * Return: pointer to the first occurrence of the character
 */

char *_strchr(char *s, char c)
{
	int x;

	/* loop through the string to find */
	for (x = 0; s[x] != '\0'; x++)
	{
		if (s[x] == c) /* check if there is a match */
			return (s + x); /* return pointer to first occrence if match is found */
	}
	if (s[x] == c)
		return (s + x);
	return ('\0'); /* return NULL if no match is found. */
}
