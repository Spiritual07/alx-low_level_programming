#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 * f4 - Function that seeds the random number generator with
 * the last character of the username
 * @usrn: username
 * @len: length of username
 * Return: a random number
 */

int f4(char *usrn, int len)
{
	srand((usrn[len - 1] ^ 14) + time(NULL));
	return (rand() & 63);
}

/**
 * f5 - Function that calculates the sum of the squares
 * of each character in the username
 * @usrn: username
 * @len: length of username
 * Return: multiplied char
 */

int f5(char *usrn, int len)
{
	int sum = 0, x;

	for (x = 0; x < len; x++)
	{
		sum += usrn[x] * usrn[x];
	}
	return (((unsigned int)sum ^ 239) & 63);
}

/**
 * f6 - Function that seeds the random number generator
 * with the first character of the username
 * @usrn: username
 * Return: a random char
 */

int f6(char *usrn)
{
	srand((usrn[0] ^ 229) + time(NULL));
	return (rand() & 63);
}

/**
 * main - Entry point
 * @argc: arguments count
 * @argv: arguments vector
 * Return: 0 (success)
 */

int main(int argc, char **argv)
{
	char keygen[7];
	int len, ch, x;
	long alph[] = {
			0x3877445248432d41, 0x42394530534e6c37, 0x4d6e706762695432,
			0x74767a5835737956, 0x2b554c59634a474f, 0x71786636576a6d34,
			0x723161513346655a, 0x6b756f494b646850 };
	(void) argc;

	len = strlen(argv[1]);

	keygen[0] = ((char *)alph)[(len ^ 59) & 63];
	ch = 0;
	for (x = 0; x < len; x++)
	{
		ch += argv[1][x];
	}
	keygen[1] = ((char *)alph)[(ch ^ 79) & 63];
	ch = 1;
	for (x = 0; x < len; x++)
	{
		ch *= argv[1][x];
	}
	keygen[2] = ((char *)alph)[(ch ^ 85) & 63];
	keygen[3] = ((char *)alph)[f4(argv[1], len)];
	keygen[4] = ((char *)alph)[f5(argv[1], len)];
	keygen[5] = ((char *)alph)[f6(argv[1])];
	keygen[6] = '\0';

	printf("%s\n", keygen);
	return (0);
}
