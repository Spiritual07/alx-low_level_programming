#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - function that prints the sum of the two diagonals
 * of a square matrix of integers.
 * @a: an input square matrix of integers
 * @size: an input integer with the size of matrix
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int x, max = size * size, sum1 = 0, sum2 = 0;

	for (x = 0; x < max; x = x + size + 1)
	{
		sum1 = sum1 + a[x];
	}
	for (x = size - 1; x < max - 1; x = x + size - 1)
	{
		sum2 = sum2 + a[x];
	}
	printf("%d, %d\n", sum1, sum2);
}
