#include "main.h"

/**
 * _abs - function that computes the absolute value of an integer.
 * @a: integer to compute absolute value
 * Return: absolute value of number or zero
 */

int _abs(int a)
{

	if (a < 0)
	{
		int _abs_val;

		_abs_val = a * -1; /* multiply by -1 to make a positive */
		return (_abs_val);
	}
	return (a);

}
