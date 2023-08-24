#include "main.h"

int s_check(char c);

/**
 * cap_string - function that capitalizes first letters of words of a string.
 * @s: input string
 * Return: modified string.
 */

char *cap_string(char *s)
{
	int x;

	for (x = 0; s[x] != '\0'; x++)
	{
		if (x == 0 && s[x] >= 'a' && s[x] <= 'z')
			s[x] = s[x] - 32;
		/* check for seperators */
		if (s[x + 1] != '\0' && s_check(s[x]) && s[x + 1] >= 'a' && s[x + 1] <= 'z')
			s[x + 1] = s[x + 1] - 32;
	}

	return (s);
}

/* define another function to check for seperators */

/**
 * s_check - Separators of words: space, tabulation, new line,
 * ,, ;, ., !, ?, ", (, ), {, and }
 * @c: an input character
 * Return: 1 if seperator, 0 otherwise
 */
int s_check(char c)
{
	int x;
	char seperators[13] = { ' ', '\t', '\n', ',', ';', '.', '!', '?',
		'"', '(', ')', '{', '}' };
	for (x = 0; x < 13; x++)
	{
		if (c == seperators[x])
			return (1);
	}
	return (0);
}
