#include <stdio.h>
#include <stdlib.h>

/**
 * main - program for number combination
 * without repetition
 * Return: always 0
 */

int main(void)
{
	int u, v, w; /* declare variable u, v and w */

		for (u = 0; u < 8; u++)
			{
			for (v = u + 1; v < 9; v++)
				{
				for (w = v + 1; w <= 9; w++)

					{
					putchar(u + '0');
					putchar(v + '0');
					putchar(w + '0');

					if (u == 7 && v == 8 && w == 9) /* check last number combination */
						continue;

					putchar(',');
					putchar(' ');

					}
				}
			}
		putchar('\n');
return (0);

}
