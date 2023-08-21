#include "main.h"

/**
 * rev_string - function that reverses a string.
 * @s: string to print in reverse
 */

void rev_string(char *s)
{
	int len = 0;
	int x;
	char temp;

	/* calculate the length of the string */
	while (s[len] != '\0')
		len++;

	/* use a for loop to revert the string */
	for (x = 0; x < len / 2; x++)
	{
		temp = s[x];
		s[x] = s[len - 1 - x];
		s[len - 1 - x] = temp;
	}


}
