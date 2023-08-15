#include "main.h"

/**
 * _isalpha - function that checks for alphabetic character
 * @c: character to be checked
 * Return: 1 if aphabet(lower or upper) 0 if otherwise
 */

int _isalpha(int c)

{
/* use ASCII values of alphabet to check for both upper and lowercase */

	if (c >= 65 && c <= 90)
	{
		return (1);
	}
	else if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
		return (0);
}
