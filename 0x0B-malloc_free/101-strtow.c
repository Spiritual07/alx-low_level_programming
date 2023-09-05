#include "main.h"
#include <stdlib.h>

void ch_free_grid(char **grid, int height);

/**
 * strtow - function that splits a string into words.
 * @str: input string to be splited
 * Return:  pointer to an array of strings (words)
 */

char **strtow(char *str)
{
	char **a_str;
	int c, height = 0, x, y, z = 0;

	if (str == NULL || *str == '\0')
		return (NULL);
	for (c = 0; str[c] != '\0'; c++)
		if (str[c] != ' ' && (str[c + 1] == ' ' || str[c + 1] == '\0'))
			height++;
	a_str = malloc((height + 1) * sizeof(char *));
	if (a_str == NULL || height == 0)
	{
		free(a_str);
		return (NULL);
	}
	for (x = z = 0; x < height; x++)
	{
		for (c = z; str[c] != '\0'; c++)
		{
			if (str[c] == ' ')
				z++;
			if (str[c] != ' ' && (str[c + 1] == ' ' || str[c + 1] == '\0'))
			{
				a_str[x] = malloc(sizeof(char) * (c - z + 2));
				if (a_str[x] == NULL)
				{
					ch_free_grid(a_str, x);
					return (NULL);
				}
				break;
			}
		}
		for (y = 0; z <= c; z++, y++)
			a_str[x][y] = str[z];
		a_str[x][y] = '\0';
	}
	a_str[x] = NULL;
	return (a_str);
}

/**
 * ch_free_grid - frees a 2 dimensional array.
 * @grid: multidimensional array of char.
 * @height: height of the array.
 */
void ch_free_grid(char **grid, int height)
{
	if (grid != NULL && height != 0)
	{
		for (; height >= 0; height--)
			free(grid[height]);
		free(grid);
	}
}
