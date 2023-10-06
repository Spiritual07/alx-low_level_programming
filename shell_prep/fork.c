#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Failed to fork\n");
	}
	else if (pid == 0)
	{
		sleep(2);
		printf("Hello from the Child process, my pid is %u\n", getpid());
	}
	else
	{
		printf("Hello from the parent process, my pid is %u\n", getpid());
	}

	return (0);
}
