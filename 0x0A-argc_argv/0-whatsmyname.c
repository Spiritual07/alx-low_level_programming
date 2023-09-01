#include <stdio.h>

/**
 * main -  program that prints its name, followed by a new line.
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	int x;

	for (x = 0; x < argc; x++)
		printf("%s\n", argv[x]);
	return (0);
}
