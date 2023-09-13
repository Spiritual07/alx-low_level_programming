#include "function_pointers.h"

/**
 * int_index -  function that searches for an integer.
 * @array: given array to be searched
 * @size: size of the array
 * @cmp: pointer to function to compare elements of the array.
 * Return: returns the index of the first element for which
 * the cmp function does not return 0 or -1 if no elements matches
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int x;

	if (array == NULL || cmp == NULL)
	{
		return (-1);
	}
	if (size <= 0)
	{
		return (-1);
	}
	for (x = 0; x < size; x++)
	{
		if (cmp(array[x]) != 0)
		{
			return (x);
		}
	}
	return (-1);
}
