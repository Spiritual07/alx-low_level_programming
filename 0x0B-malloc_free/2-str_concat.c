#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * *str_concat - function that concatenates two strings.
 * @s1: string 1
 * @s2: string 2
 * Return: pointer to concatenated string
 */

char *str_concat(char *s1, char *s2)
{
	int x, y, z, len;
	char *p;
/* Check if NULL are passed in either of s1 or s2 */
	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
/* check for length of string s1 and s2 */
	for (x = 0; s1[x] != '\0'; x++)
		;
	for (y = 0; s2[y] != '\0'; y++)
		;
/* allocate memory to concatenated string */
	p = malloc(sizeof(char) * (x + y + 1));
/* check if malloc failed */
	if (p == NULL)
	{
		return (NULL);
	}
/* copy characters from s1 into the new memory */
	for (z = 0; z < x; z++)
	{
		p[z] = s1[z];
	}
/* copy character from s2 into the new memory */
	for (len = 0; len < y; len++, z++)
	{
		p[z] = s2[len];
	}
	p[z] = '\0'; /* add null bite to characters in the new memory */
	return (p); /* return pointer to new memory */
}
