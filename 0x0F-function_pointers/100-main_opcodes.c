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
	char *ptrM; /* declare function poiter */
	int x = 0, nBytes;

	if (ac != 2) /* check if arguments entered is correct */
	{
		printf("Error\n");
		exit(1);
	}
	nBytes = atoi(av[1]); /* convert av array to interger */

	if (nBytes < 0) /* check if byte is less than 0 */
	{
		printf("Error\n");
		exit(2);
	}

	ptrM = (char *)main; /* initialize pointer to main function */

/* Print the hexadecimal representation of the first nBytes of the program */
	while (x < nBytes)
	{
		printf("%02x", ptrM[x] & 0xFF);
			x++;
		if (x < nBytes)
			printf(" ");
	}
	printf("\n");

	return (0);
}
