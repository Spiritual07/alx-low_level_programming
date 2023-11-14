#include "main.h"

/**
 * _strstr - function that locates a substring.
 * @haystack: input string
 * @needle: input string
 * Return:  pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */

char *_strstr(char *haystack, char *needle)
{
	/* Loop through each character in the haystack */
	for (; *haystack != '\0'; haystack++)
	{
		char *start = haystack;
		char *sub = needle;

		/* Loop through while characters in start and sub are */
		/* the same and sub is not at the end */
		while (*start == *sub && *sub != '\0')
		{
			/* Move to next characters in start and sub */
			start++;
			sub++;
		}
	/* If we've reached the end of sub, it means */
	/* we've found the substring in haystack */
		if (*sub == '\0')
			return (haystack);
	}

	return (0); /* return NULL if substring not found */
}
