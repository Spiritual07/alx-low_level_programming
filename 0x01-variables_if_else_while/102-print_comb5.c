#include <stdio.h>

/**
 * main -  program that prints all possible
 * combinations of two two-digit numbers.
 * Return: always 0
 */

int main(void)
{
	int s, t, u, v;

	for (s = 0; s <= 9; s++)
	{
		for (t = 0; t <= 9; t++)
		{
			for (u = 0; u <= 9; u++)
			{
				for (v = 0; v <= 9; v++)
				{
					if (((u + v) > (s + t) &&  u >= s) || s < u)
					{
						putchar(s + '0');
						putchar(t + '0');
						putchar(' ');
						putchar(u + '0');
						putchar(v + '0');
					if (s + t + u + v == 0 && s == 9)
						{
						break;
						}
					else
					{
					putchar(',');
					putchar(' ');
					}
					}
				}
			}
		}
	}

	putchar('\n');

	return (0);
}
