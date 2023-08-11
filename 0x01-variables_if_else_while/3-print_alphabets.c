#include <stdio.h>

/**
 * main - program to print alphabet
 * in lower and uppercase
 * Return: always 0
 */

int main(void)
{
char alphabet;

for (alphabet = 'a'; alphabet <= 'z'; alphabet++)
	{
	putchar(alphabet);
	}
for (alphabet = 'A'; alphabet <= 'Z'; alphabet++)
	{
	putchar(alphabet);
	}
	putchar('\n');

return (0);

}
