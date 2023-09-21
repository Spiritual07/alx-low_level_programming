#include "lists.h"

/**
 * startupMsg - function that prints a message before the main function runs
 */

/* Apply the constructor attribute to startupMsg() */
/* so that it is executed before main() */
void startupMsg(void)__attribute__((constructor));

void startupMsg(void)
{
	printf("You're beat! and yet, you must allow,\nI bore my house upon my back!\n");
}
