/* Function to compute the length of a string */
#include "main.h"

/**
 * _strlen - function that returns the length of a string.
 * @s: integer to return it's length.
 * Return: integer (string length)
 */

int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}


/* Function to reverse a string */
#include "main.h"

/**
 * rev_string - function that reverses a string.
 * @str: string to print in reverse
 * @len: len of string
 */

void rev_string(char *str, int len)
{
	char tmp;
	int i;

	for (i = 0; i < len / 2; i++)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
}

/* The main function */
#include "main.h"

/**
 * infinite_add - function that adds two numbers in given char arrays
 * @n1: The first number
 * @n2: The second number
 * @r: Pointer to the buffer to store result
 * @size_r: The size of the buffer
 * Return: 0 if buffer too small to store result, else return pointer to buffer
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int l1, l2, i, sum, num1, num2, carry = 0;

	/* Measure lengths of input strings */
	l1 = _strlen(n1);
	l2 = _strlen(n2);

	/* Check if buffer is large enough to hold result */
	if (l1 + 2 > size_r || l2 + 2 > size_r)
		return (0);

	/* Add numbers digit by digit and Convert char to int by subtracting '0' */
	for (i = 0; i < l1 || i < l2; i++)
	{
		num1 = (i < l1) ? n1[l1 - i - 1] - '0' : 0;
		num2 = (i < l2) ? n2[l2 - i - 1] - '0' : 0;
		/* Add digits and carry from previous step */
		sum = num1 + num2 + carry;
		carry = (sum >= 10) ? 1 : 0;
		r[i] = (sum % 10) + '0';
	}

	/* Check if there is a carry after the last step */
	if (carry > 0)
		r[i++] = carry + '0';

	r[i] = '\0'; /* End of string marker */

	/* Reverse the result string */
	rev_string(r, i);

	return (r);
}
