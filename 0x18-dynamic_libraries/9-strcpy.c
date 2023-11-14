#include "main.h"

/**
 * _strcpy - function that copies the string pointed to
 * by src, including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 * @dest: destination of string
 * @src: source of string
 * Return: pointer to dest.
 */

char *_strcpy(char *dest, char *src)
{
	char *p = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';

	return (p);
}
