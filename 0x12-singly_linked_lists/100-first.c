#include "lists.h"

/* using constructor */

void startupMsg(void)__attribute__((constructor));

/**
 * startupMsg - prints a message before main function runs
 *
 * Description: The function is marked with the constructor attribute,
 * which ensures that it is called before main().
 * It prints a message.
 *
 * Return: void
 */

void startupMsg(void)
{
	printf("You're beat! and yet, you must allow,\n"
					"I bore my house upon my back!\n");
}
