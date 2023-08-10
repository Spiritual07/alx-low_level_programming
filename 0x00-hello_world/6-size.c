#include <stdio.h>

/**
 * main - C program that
 * prints sizes of various
 * type on the computer it's
 * runned on.
 * Return: always 0
 */

int main(void)
{
printf("size of a char: %lu byte(s)\n", sizeof(char));
printf("size of an int: %lu byte(s)\n", sizeof(int));
printf("size of a long int: %lu byte(s)\n", sizeof(long));
printf("size of a long long int: %lu byte(s)\n", sizeof(long long));
printf("size of a float: %lu byte(s)\n", sizeof(float));

return (0);

}

