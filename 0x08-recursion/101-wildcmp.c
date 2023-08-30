#include "main.h"

/**
 * wildcmp - function that compares two strings
 * @s1: first input string for comparison
 * @s2: second input string for comparison
 * Return: 1 if identical, otherwise return 0
 */

int wildcmp(char *s1, char *s2)
{
	/* check for null character for both strings */
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1);
	}
	else if (*s1 == *s2) /* compare both string */
	{
		/* recursive call of wildcmp funtion for comparison */
		return (wildcmp(s1 + 1, s2 + 1));
	}
	else if (*s2 == '*') /* check if character in s2 is a wildcard */
	{
		if (*(s2 + 1) == '*') /* check if next character is also a wildcard */
		{
			return (wildcmp(s1, s2 + 1)); /* compare rest of s2 against s1 */
		}
		/* compare two possible match for the wildcard */
		else if (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1))
		{
			return (1);
		}
	}
	return (0); /* return 0 if none of the above condition are met */
}
