#include <stdio.h>
#include <stdlib.h>

/**
 * main - program that prints the minimum number of
 * coins to make change for an amount of money.
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	int cent; /* variable to stor amount of money */
	int coins = 0; /* variable to store minimum number of coing for change */

	if (argc != 2) /* check if num argument passed is not 2 */
	{
		printf("Error\n"); /* print error if not */
		return (1);
	}
	cent = atoi(argv[1]); /* convert second argument to integer */
	/* loop while the amount of money is more than 0 and perform the */
	/* statements inside the loop */
	for (; cent > 0; coins++)
	{
		if (cent >= 25)
			cent -= 25;
		else if (cent >= 10)
			cent -= 10;
		else if (cent >= 5)
			cent -= 5;
		else if (cent >= 2)
			cent -= 2;
		else if (cent >= 1)
			cent -= 1;
	}
	printf("%d\n", coins); /* print minimum number of coin to make change */
	return (0);
}
