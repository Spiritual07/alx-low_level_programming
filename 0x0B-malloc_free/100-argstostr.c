#include "main.h"
#include <stdlib.h>

/**
 * *argstostr - function that concatenates all the arguments of your program.
 * @ac: argument count
 * @av: argument vector
 * Return: Returns a pointer to a new string, or NULL if it fails
 */

char *argstostr(int ac, char **av)
{
	int x, y;
	int z = 0;
	int len = 0;
	char *str;

	if (ac == 0)
	{
		return (NULL);
	}
/* calculate length of string to be concatenated */
	for (x = 0; x < ac; x++)
	{
		if (av[x] == NULL) /* check if av is NULL */
			return (NULL);
		for (y = 0; av[x][y] != '\0'; y++)
		{
			len++;
		}
		len++; /* account for null terminator at the end of string */
	}
	/* allocate memory to the concatenated string */
	str = malloc(sizeof(char) * (len + 1));
	/* check if memory allocation failed */
	if (str == NULL)
	{
		return (NULL);
	}
	/* copy characters from av to str */
	for (x = z = 0; x < ac; x++, z++)
	{
		for (y = 0; av[x][y] != '\0'; y++)
		{
			str[z] = av[x][y];
			z++;
		}
		str[z] = '\n'; /* add newline character after each string */
	}
	str[z] = '\0'; /* add null terminator */
	return (str); /* return pointer to new string */
}
