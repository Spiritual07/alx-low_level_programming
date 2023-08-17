#include <stdio.h>

/**
 * main - program that prints the numbers from 1 to 100,
 * followed by a new line. But for multiples of three print
 * Fizz instead of the number and for the multiples of five
 * print Buzz. For numbers which are multiples of both three
 * and five print FizzBuzz
 * Return: 0 (success)
 */

int main(void)
{
	int a;

	for (a = 1; a <= 100; a++)
	{
		if (a % 15 == 0)
			printf("FizzBuzz ");

		else if (a % 5 == 0)
		{
			if (a == 100)
			{
				printf("Buzz");
				printf("\n");
			}
			else
				printf("Buzz ");
		}
		else if (a % 3 == 0)
			printf("Fizz ");

		else
			printf("%d ", a);
	}

	return (0);
}
