#include <stdio.h>

/**
 * main - program that prints the name of the file it was compiled from.
 * Return: 0 (success)
 */

#define NAME __FILE__

int main(void)
{

	printf("%s\n", NAME);

	return (0);
}
