#include "main.h"

/**
 * leet -  function that encodes a string into 1337.
 * @s: input string
 * Return: encoded string
 */

char *leet(char *s)
{
	int x, y;
	char main_str[] = {'a', 'A', 'e', 'E', 'o', 'O', 't', 'T', 'l', 'L'},
		sub_str[] = {'4', '4', '3', '3', '0', '0', '7', '7', '1', '1'};
	/* loop through each character until NULL character */
	for (x = 0; s[x] != '\0'; x++)
	{
		for (y = 0; y < 10; y++)
		{
			/* check if current character of input string matches main */
			if (s[x] == main_str[y])

			/* Replace the current character with the corresponding */
			/* character from the sub_str array */
				s[x] = sub_str[y];
		}
	}
	return (s);
}
