#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - program to asign random
 * number to n each time executed
 * Return: always 0
 */

int main(void)
{
int n;
srand(time(0));
n = rand() - RAND_MAX / 2;

	if (n % 10 > 0)
	{
		printf("%d is positive\n", n);
	}
	else if (n % 10 == 0)
	{
		printf("%d is zero\n", n);
	}
	else if (n % 10 < 0)
	{
		printf("%d is negative\n", n);
	}
return (0);
}
