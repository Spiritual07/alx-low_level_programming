#include <stdio.h>
#include <stdlib.h>

/**
 * main - program that prints the opcodes of its own main function.
 * @ac: argument count
 * @av: array of arguments
 * Return: 0 (success)
 */

int main(int ac, char *av[])
{
	char *ptrM;
	int x = 0, nBytes;

	if (ac != 2)
	{
		printf("Error\n");
		exit(1);
	}
	nBytes = atoi(av[1]);

	if (nBytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	ptrM = (char *)main;

	if (nBytes > 0)
	{
		while (x < (nBytes - 1))
		{
			printf("%02hhx\n", ptrM[x++]);
		}
		printf("%hhx\n", ptrM[x]);
	}
	return (0);
}
