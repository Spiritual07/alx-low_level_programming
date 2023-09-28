#include "main.h"

/**
 * binary_to_uint - function that converts a binary number to an unsigned int.
 * @b: pointer to a string of 0 and 1 chars
 * Return: the converted number, or 0 if there is one or more
 * chars in the string b that is not 0 or 1 or if b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	int x, len = strlen(b), power = 1;
	unsigned int uint = 0;

	if (b == NULL)
	{
		return (0);
	}
	for (x = 0; x < len; x++)
	{
		if (b[x] != '0' && b[x] != '1')
		{
			return (0);
		}
	}
	for (x = len - 1; x >= 0; x--)
	{
		if (b[x] == '1')
		{
			uint = uint + power;
		}
		power = power * 2;
	}
	return (uint);
}
