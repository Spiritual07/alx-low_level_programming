#include <stddef.h>
#include "shell.h"

int _strcspn(char *s, char *reject)
{
	int count = 0, x, y;

	for (x = 0; s[x] != '\0'; x++)
	{
		for (y = 0; reject[y] != '\0'; y++)
		{
			if (s[x] == reject[y])
			{
				return (count);
			}
		}
		count++;
	}
	return (count);
}
