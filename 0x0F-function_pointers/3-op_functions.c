#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_add - adds two numbers
 * @a: first input number
 * @b: second input number
 * Return: sum of the two numbers.
 */

int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtracts two numbers
 * @a: first input number
 * @b: second input number
 * Return: diffrence of the two numbers.
 */

int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiplies two numbers
 * @a: first input number
 * @b: second input number
 * Return: result of multiplication of the two numbers.
 */

int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divides two numbers
 * @a: first input number
 * @b: second input number
 * Return: result of division of the two numbers.
 */

int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	else
		return (a / b);
}

/**
 * op_mod - modulo of two numbers
 * @a: first input number
 * @b: second input number
 * Return: result of modulo of the two numbers.
 */

int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
