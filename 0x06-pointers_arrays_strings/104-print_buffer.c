#include <stdio.h>
#include "main.h"

/**
 * print_buffer - function that prints a buffer.
 * @size: size of the buffer
 * @b: pointer to buffer
 */

void print_buffer(char *b, int size)
{
	int x, y;

	/* If size is less than or equal to 0, print newline */
	if (size <= 0)
		putchar('\n');
	else
	{
		/* loop through the buffer and print the index */
		for (x = 0; x < size; x += 10)
		{
			printf("%08x: ", x);
			/* Loop to print each byte in hexadecimal */
			for (y = 0; y < 10; y++)
			{
				/* Print space after every 2 bytes */
				if (y % 2 == 0 && y > 0)
					printf(" ");
				/* Print space if end of buffer is reached */
				if (y + x > size - 1)
					printf("  ");
				else
					printf("%.2x", b[y + x]); /* Print byte in hex */
			}
			putchar(' ');
			/* Loop to print each byte in ASCII */
			for (y = 0; y < 10 && y + x <= size - 1; y++)
			{
				/* Print character if it's printable ASCII */
				if (b[y + x] >= ' ' && b[y + x] <= '~')
					putchar(b[y + x]);
				else
					putchar('.'); /* Print dot for non-printable ASCII */
			}
			putchar('\n');
		}
	}
}
