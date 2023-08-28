#include "main.h"

/**
 * _strspn -  function that gets the length of a prefix substring.
 * @s: string to be scanned
 * @accept: string containing characters to be matached
 * Return: number of bytes in the initial segment of s
 */

unsigned int _strspn(char *s, char *accept)
{
/* initializes a counter to keep track of the number of matching characters. */
	unsigned int count = 0;
	int x, y;

/* loop through string s until it hits NULL character or space */
	for (x = 0; s[x] != '\0' && s[x] != ' '; x++)
	{
/* loop over string accept until it hits NUll character */
		for (y = 0; accept[y] != '\0'; y++)
		{
			if (s[x] == accept[y]) /* check for match between s and accept */
			{
				count++; /* count incremented */
/* break loop, move to next character in s when matching character is found */
				break;
			}
		}
		if (s[x] != accept[y])
			break;
	}
	return (count);
}
