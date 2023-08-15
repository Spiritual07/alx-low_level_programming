#include "main.h"

/**
 * _islower - checks for lowercase letters
 * @c: character to be checked
 * Return: 1 if lowercase, 0 if otherwise
 */

int _islower(int c)

{

/* Use ASCII values of lowercase letter a-z */

	if (c >= 97 && c <= 122)
	{
		return (1);
	}

	return (0);
}
