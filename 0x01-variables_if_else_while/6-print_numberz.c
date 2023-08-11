#include <stdio.h>

/**
 * main - printing single digits number
 * of base 10 using putchar
 * Return: always 0
 */

int main(void)
{
/* declare integer variable for single digit number */

int a;
	for (a = 0; a <= 9; a++)
	{
	putchar(a + '0');
	}
putchar('\n');

return (0);

}

