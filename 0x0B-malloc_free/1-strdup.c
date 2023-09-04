#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * *_strdup - function that returns a pointer to a newly allocated
 * space in memory, which contains a copy of the string given as a parameter.
 * @str: string give that is to be copied
 * Return: pointer to the coppied string, NULL if insufficient memory available
 */

char *_strdup(char *str)
{
	int x, y;
	char *cpy;

	if (str == 0)
	{
		/* return NULL if string is empty */
		return (NULL);
	}
	/* Check for length of original string */
	for (x = 0; str[x] != '\0'; x++)
		;
	/* allocate memory to hold duplicate string */
	cpy = (char *)malloc(sizeof(char) * (x + 1));

	/* return NULL if duplicate string is empty */
	if (cpy == NULL)
	{
		return (NULL);
	}
	/* duplicate string by copying characters from given string */
	/* to newly allocated memory using for loop */
	for (y = 0; y <= x; y++)
	{
		cpy[y] = str[y];
	}		
	return (cpy); /* return duplicate string */
}
