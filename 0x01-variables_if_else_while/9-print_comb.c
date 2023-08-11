#include <stdio.h>

/**
 * main - program for possible combine
 * combination of single digits number
 *Return: always 0
 */

int main(void)

{
/* declare variable for single digit number */

char (c);
	for (c = '0'; c <= '9'; c++)
	{
	putchar(c);
		if (c != '9')
		{
		putchar(',');
		putchar(' ');
		}
	}
	putchar('\n');

	return (0);

}
