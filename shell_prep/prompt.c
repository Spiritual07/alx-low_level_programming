#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	ssize_t read_line;
	char *lineptr = NULL;
	size_t n = 0;

	printf("$");

	read_line = getline(&lineptr, &n, stdin);

	if (read_line == -1)
	{
		if (feof(stdin))
		{
			printf("End of file reached\n");
		}
		else
		{
			printf("Error reading line\n");
		}
		free(lineptr);
		exit(98);
	}
	printf("%s", lineptr);
	free(lineptr);

	return (0);
}
