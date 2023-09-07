#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - function that concatenates two strings
 * @s1: input string 1
 * @s2: input string 2
 * @n: number of byts
 * Return: pointer to concatenated string
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *con_str;
	unsigned int x, y, z, len;

	/* check if any of the string is NULL and treat as empty */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* calculate string length of both strings */
	for (x = 0; s1[x] != '\0'; x++)
		;
	for (y = 0; s2[y] != '\0' && y < n; y++)
		;

	/* Allocate memory and check if memory allocation failed */
	con_str = malloc(sizeof(char) * (x + y + 1));

	if (con_str == NULL)
		return (NULL);

	/* copy s1 and s2 to allocated memory */
	for (z = 0; z < x; z++)
		con_str[z] = s1[z];

	for (len = 0; len < y; len++)
		con_str[x + len] = s2[len];

	con_str[x + y] = '\0'; /* add null character to concatenated string */

	return (con_str);
}
