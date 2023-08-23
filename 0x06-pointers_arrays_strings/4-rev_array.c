#include "main.h"

/**
 * reverse_array - function that reverses the content of an array of integers.
 * @a: arrays of integer
 * @n: number of elemet to reverse
 */

void reverse_array(int *a, int n)
{
	int i, temp;

	for (i = 0; i < n--; i++)
	{
		temp = a[i];
		a[i] = a[n];
		a[n] = temp;
	}

}
