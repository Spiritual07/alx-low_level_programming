#include "main.h"

/**
 * jack_bauer -  function that prints every minute of
 * the day of Jack Bauer, starting from 00:00 to 23:59.
 * Return: 0
 */

void jack_bauer(void)
{
	int w, x, y, z;

	for (w = 0; w <= 2; w++)
	{
		for (x = 0; x <= 3; x++)
		{
			for (y = 0; y <= 5; y++)
			{
				for (z = 0; z <= 9; z++)
				{

					_putchar(w + '0');
					_putchar(x + '0');
					_putchar(58);
					_putchar(y + '0');
					_putchar(z + '0');
					_putchar('\n');
				}

			}

		}

	}

}
