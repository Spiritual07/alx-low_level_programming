#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - program that performs simple operations.
 * @ac: argument count
 * @av: array of argument
 * Return: 0 (success)
 */

int main(int ac, char *av[])
{
	int num1, num2, result = 0;
	int (*fptr)(int, int);/* declare function pointer */

/* initialize function pointer with operator selector function */
	fptr = get_op_func(av[2]);

	if (ac != 4) /* check if number of argument is correct */
	{
		printf("Error\n");
		exit(98);
	}
	if (fptr == NULL) /* check if function pointer is empty */
	{
		printf("Error\n");
		exit(99);
	}
	/* convert array of argument to numbers */
	num1 = atoi(av[1]);
	num2 = atoi(av[3]);
	result = fptr(num1, num2);/* call function pointer to perform the operation */
	printf("%d\n", result);

	return (0);
}
