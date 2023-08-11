#include <stdio.h>

/**
 * main - program that prints the alphabet
 * in lowercase
 * Return: always 0
 */

int main(void)
{
	/* declare the variable alphabet */
	char alphabet;

	for (alphabet = 'a'; alphabet <= 'z'; alphabet++)
	{
	/* print result using putchar */
	putchar(alphabet);
	}
	putchar('\n');

return (0);

}
