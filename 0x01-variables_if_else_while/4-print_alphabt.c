#include <stdio.h>

/**
 * main - program listing alphabet
 * i lowercase excluding e and q
 * Return: always 0
 */

int main(void)
{
/* declare variable for alphabet */
char alphabet;

	for (alphabet = 'a'; alphabet <= 'z'; alphabet++)
		if (alphabet != 'e' && alphabet != 'q')
		putchar(alphabet);
	putchar('\n');
return (0);

}
