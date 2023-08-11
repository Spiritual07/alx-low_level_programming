#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - this program will
 * asign random value to
 * variable n each time
 * it's executed
 * Return: always 0
 */

int main(void)
{
int n;
srand(time(0));
n = rand() - RAND_MAX / 2;

	if (n % 10 > 5) /* divide n by 10 to extract the last digit of n */
	{
		printf("Last digit of %d is %d and is greater than 5\n", n, n % 10);
	}
	else if (n % 10 == 0)
	{
		printf("Last digit of %d is %d and is 0\n", n, n % 10);
	}
	else
	{
		printf("Last digit of %d is %d and is less than 6 and not 0\n", n, n % 10);
	}

return (0);

}
