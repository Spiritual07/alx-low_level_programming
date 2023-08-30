#include "main.h"

int isDivisible(int num, int divisor);

/**
 * is_prime_number - function that returns 1 if the input integer
 * is a prime number, otherwise return 0
 * @n: input number to check if if it's prime
 * Return: 1 if prime number, 0 if otherwise
 */

int is_prime_number(int n)
{
	if (n < 2) /* numbers less than two are not prime numbers */
	{
		return (0);
	}
	else if (n <= 3) /* 2 and 3 are prime numbers */
	{
		return (1);
	}
	else
	{
		return (isDivisible(n, 2));/* for numbers greater than 2, check divisibity */
									/* starting from 2 */
	}
}

/**
 * isDivisible - function to check for prime by checking the
 * it divisibiltity
 * @num: number to check if it's prime
 * @divisor: divisor to check number divisibilty
 * Return: 1 if prime, 0 if not.
 */

int isDivisible(int num, int divisor)
{
	if (num % divisor == 0)
	{
		return (0); /* is not a prime */
	}
	else if (divisor == num / 2)
	{
		return (1); /* it's a prime number */
	}
	else
	{
		return (isDivisible(num, divisor + 1));
	}
}
