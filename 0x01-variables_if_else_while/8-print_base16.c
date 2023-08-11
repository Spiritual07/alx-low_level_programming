#include <stdio.h>

/**
 * main - program that prints all
 * numbers of base 16 in lower case
 * Return: always 0
 */

int main(void)
{
/* declare variable for base 16 numbers */

char (base_16);
	for (base_16 = '0'; base_16 <= '9'; base_16++)
		{
		putchar(base_16);
		}
	for (base_16 = 'a'; base_16 <= 'f'; base_16++)
		{
		putchar(base_16);
		}
	putchar('\n');

return (0);

}
