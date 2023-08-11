#include <stdio.h>

/**
 * main - program for reverse alphabet
 * Return: always 0
 */

int main(void)
{

/* declare variable for alphabet */

char (alphabet);

for (alphabet = 'z'; alphabet >= 'a'; alphabet--)
	{
	putchar(alphabet);
	}
	putchar('\n');
return (0);

}
