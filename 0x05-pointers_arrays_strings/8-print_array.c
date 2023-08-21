#include "main.h"
#include <stdio.h>

/**
 * print_array -  function that prints n elements of an
 * array of integers, followed by a new line
 * @a: array of integers
 * @n: number of elements of the array to be printed
 */

void print_array(int *a, int n)
{
	int x;

	for (x = 0; x < n; x++)
	{
		printf("%d", a[x]);
		if (x < n - 1)
			printf(", ");
	}
	printf("\n");
}
