#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	char *av[] = {"/bin/ls", "-l", "/usr/", NULL};
	int ex;

	printf("Before execve\n");
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
	}
	else if (pid == 0)
	{
		ex = execve(av[0], av, NULL);
		if (ex == -1)
		{
			perror("Error");
		}
	}
	else
	{
		wait(NULL);
		printf("After execve\n");
	}

	return (0);
}
