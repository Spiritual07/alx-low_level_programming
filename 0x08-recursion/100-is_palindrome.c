#include "main.h"

/**
 * _strlen_recursion - function that returns the length of a string.
 * @s: input string
 * Return: string length(integer)
 */

int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	else
	{
		return (1 + _strlen_recursion(s + 1));
	}
}

/**
 * palindrome_check - supporting function for _palindrome
 * @s: input string to check
 * @len: length of string
 * @count: keep count of position in string
 * Return: 1 if palindrome, 0 if otherwise
 */

int palindrome_check(char *s, int len, int count)
{
	if (count >= len)
	{
		return (1);
	}
	else if (s[len] == s[count])
	{
		return (palindrome_check(s, len - 1, count + 1));
	}
	else
	{
		return (0);
	}
}

/**
 * is_palindrome - function that checks if a string is palindrome or not
 * @s: string to check
 * Return: 1 if palindrome, 0 if not.
 */

int is_palindrome(char *s)
{
	int length = _strlen_recursion(s);
	int count = 0;

	return (palindrome_check(s, length - 1, count));
}
