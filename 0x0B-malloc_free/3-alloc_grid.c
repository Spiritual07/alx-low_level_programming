#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * **alloc_grid - function that returns a pointer to a
 * 2 dimensional array of integers
 * @width: width of array
 * @height: height of array
 * Return: pointer to array
 */

int **alloc_grid(int width, int height)
{
	int **array;
	int x, y;
/* check if width or length is 0 or less */
	if ((width <= 0) || (height <= 0))
	{
		return (NULL);
	}
/* allocate memory for the 2D array */
	array = malloc(sizeof(int *) * height);

/* check if memory allocation failed */
	if (array == NULL)
	{
		return (NULL);
	}
/* allocate memory for each row of the 2D array */
	for (x = 0; x < height; x++)
	{
		array[x] = malloc(sizeof(int) * width);
		if (array[x] == NULL)
		{
			return (NULL);
		}
		for (y = 0; y < width; y++)
		{
			array[x][y] = 0; /* initialize element of array to 0 */
		}
	}
	return (array); /* return point to the array */
}
