#include "main.h"

/**
 * string_toupper - function that changes all lowercase
 * letters of a string to uppercase.
 * @str: string to change to upper
 * Return: poiter to str
 */

char *string_toupper(char *str)
{
	char *p = str; /* initialize pointer to store starting point of string */

	/* loop through string until a NULL character is encountered */
	for (; *str != '\0'; str++)
	{
		/* check if current character is lowercase */
		if (*str >= 'a' && *str <= 'z')
			*str = *str - 32; /* Convert to uppercase by subtracting ASCII difference */
	}
	return (p);
}
