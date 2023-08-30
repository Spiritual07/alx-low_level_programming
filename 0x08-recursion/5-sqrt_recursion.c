#include "main.h"

int check_sqrt(int x, int n);

/**
 * _sqrt_recursion - function that returns the natural
 * square root of a number.
 * @n: input number
 * Return: natural square root of input number
 */

int _sqrt_recursion(int n)
{
	return (check_sqrt(1, n));
}

/**
 * check_sqrt - function that check for perfect square of a number
 * @x: number to be squared
 * @n: number to check for perfect square
 * Return: perfect square (n)
 */

int check_sqrt(int x, int n)
{
	if (x * x > n)
	{
		return (-1);
	}
	else if (x * x == n)
	{
		return (x);
	}
	return (check_sqrt(x + 1, n));
}
