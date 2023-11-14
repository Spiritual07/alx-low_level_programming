#include "main.h"

/**
 * _atoi - function that converts string to an integer
 * @s: Number of string to be converted
 * Return: integer from the conversion
 */

int _atoi(char *s)
{
	int sign = 1;
	unsigned int total = 0;
	char null_flag = 0;

	for (; *s; s++)
	{
		if (*s == '-')
			sign *= -1;

		if (*s >= '0' && *s <= '9')
		{
			null_flag = 1;
			total = total * 10 + *s - '0';
		}

		else if (null_flag)
			break;
	}

	if (sign < 0)
		total = (-total);

	return (total);
}
