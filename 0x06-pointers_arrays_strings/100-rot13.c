#include "main.h"

/**
 * rot13 - function that encodes a string using rot13.
 * @s: input string
 * Return: encoded string
 */

char *rot13(char *s)
{
	int x;

	for (x = 0; s[x] != '\0'; x++)
	{
		for (; (s[x] >= 'a' && s[x] <= 'z') || (s[x] >= 'A' && s[x] <= 'Z'); x++)
		{
			if ((s[x] >= 'a' && s[x] <= 'm') || (s[x] >= 'A' && s[x] <= 'M'))
				s[x] = s[x] + 13;
			else
				s[x] = s[x] - 13;
		}
	}
	return (s);
}
