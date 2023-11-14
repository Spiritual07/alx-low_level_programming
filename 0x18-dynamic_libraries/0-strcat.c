#include "main.h"

/**
 * _strcat - function that concatenates two strings
 * @dest: dest string
 * @src: src string
 * Return: Pointer to resulting string dest.
 */

char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;

	*dest = '\0';

	return (p);
}
