#include "function_pointers.h"

/**
 * array_iterator -  function that executes a function given as
 * a parameter on each element of an array.
 * @array: given array
 * @size: size of the array
 * @action: a pointer to the function you need to use
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t x;

	for (x = 0; x < size; x++)
	{
		action(array[x]);
	}
}
