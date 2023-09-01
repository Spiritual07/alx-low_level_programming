#include <stdio.h>
#include <stdlib.h>

/**
 * main -  program that multiplies two numbers.
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	int x, num1, num2;
	int mul;

	if (argc < 2)
	{
		printf("Error\n");
		return (1);
	}
	for (x = 0; x < argc; x++)
	{
		num1 = atoi(argv[1]);
		num2 = atoi(argv[2]);
		mul = num1 * num2;
	}
	printf("%d\n", mul);

	return (0);
}
