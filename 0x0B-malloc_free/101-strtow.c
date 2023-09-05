#include "main.h"
#include <stdlib.h>

/**
 * strtow - function that splits a string into words.
 * @str: input string to be splited
 * Return:  pointer to an array of strings (words)
 */

char **strtow(char *str)
{
	char **a_str;
	int c, height = 0, x, y, z = 0, w_len = 0;

	if (str == NULL || *str == '\0')
		return (NULL);
	for (c = 0; str[c] != '\0'; c++)
	{
		if (str[c] != ' ' && (str[c + 1] == ' ' || str[c + 1] == '\0'))
			height++;
	}
	a_str = (char **)malloc((height + 1) * sizeof(char *));
	if (a_str == NULL || height == 0)
	{
		free(a_str);
		return (NULL);
	}
	for (x = 0, z = 0; x < height; x++)
	{
		while (str[z] == ' ')
			z++;
		while (str[z + w_len] != ' ' && str[z + w_len] != '\0')
			w_len++;
		a_str[x] = (char *)malloc((w_len + 1) * sizeof(char));
		if (a_str[x] == NULL)
		{
			for (y = 0; y < x; y++)
				free(a_str[y]);
			free(a_str);
			return (NULL);
		}
		for (y = 0; y < w_len; y++)
			a_str[x][y] = str[z + y];
		a_str[x][y] = '\0';
		z = z + w_len;
	}
	a_str[x] = (NULL);
	return (a_str);
}
