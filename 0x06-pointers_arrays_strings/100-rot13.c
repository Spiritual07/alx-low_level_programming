#include "main.h"

/**
 * rot13 - function that encodes a string using rot13.
 * @s: input string
 * Return: encoded string
 */

char *rot13(char *s)
{
	int x, y;
	char orig[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (x = 0; s[x] != '\0'; x++)
	{
		for (y = 0; y < 52; y++)
		{
			if (s[x] == orig[y])
			{
				s[x] = rot13[y];
				break;
			}
		}
	}
	return (s);
}
