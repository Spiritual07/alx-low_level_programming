#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signalHandler(int signal)
{
	printf("Signal received is %d\n", signal);
}

int main(void)
{
	signal(SIGINT, signalHandler);
	printf("Running...., press ctrl+z to exit;)\n");

	while (1)
	{
		sleep(2);
	}
	return (0);
}
