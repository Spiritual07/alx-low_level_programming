#include <stdio.h>

/**
 * main - program for number combination
 * without repetition
 * Return: always 0
 */

int main(void)

{
	int u, v; /* declare variable u and v */

		for (u = 0; u < 9; u++)
		{
			for (v = u + 1; v < 10; v++)
			{
			putchar(u + '0');
			putchar(v + '0');
			if (u != 8) /* don't print comma after last number */
				{
				putchar(',');
				putchar(' ');
				}
			}
		}
	putchar('\n');
return (0);

}
