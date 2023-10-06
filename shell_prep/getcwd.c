#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *result;
	char buf[500];
	size_t size;

	size = sizeof(buf);

	result = getcwd(buf, size);
	if (result = NULL)
	{
		perror("ERROR");
	}
	else
	{
		printf("The current working directory is: %s\n", buf);
	}
	return (0);
}
