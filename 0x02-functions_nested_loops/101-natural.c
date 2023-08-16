#include <stdio.h>

/**
 * main -  a program that computes and prints
 * the sum of all the multiples of 3 or 5
 * below 1024 (excluded)
 * Return: always 0
 */

int main(void)
{
	int x, sum = 0;

	for (x = 0; x < 1024; x++)
	{
		if ((x % 3) == 0 || (x % 5) == 0)
			sum = sum + x;
	}

	printf("%d\n", y);

	return (0);
}

