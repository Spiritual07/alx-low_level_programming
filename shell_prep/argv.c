#include <stdio.h>

int main(int ac __attribute__((unused)), char *av[])
{
	int x;

	for (x = 0; av[x]; x++)
	{
		printf("%s\n", av[x]);
	}

	return (0);
}
