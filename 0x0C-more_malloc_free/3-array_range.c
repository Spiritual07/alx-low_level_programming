#include "main.h"
#include <stdlib.h>

/**
 * array_range - function that creates an array of integers.
 * @min: min array value
 * @max: max array value
 * Return: the pointer to the newly created array
 */

int *array_range(int min, int max)
{
	int *ptArr;
	int x, arr_elements;

	/* Check if input range is valid */
	if (min > max)
	{
		return (NULL);
	}
	/* calculate number of elements in the array */
	arr_elements = (max - min) + 1;

	/* allocate memory to the array */
	ptArr = malloc(sizeof(int) * arr_elements);
	if (ptArr == NULL)
	{
		return (NULL);
	}
	/* populate array with values from min to max */
	for (x = 0; x < arr_elements; x++)
		ptArr[x] = min + x;
	return (ptArr);
}
