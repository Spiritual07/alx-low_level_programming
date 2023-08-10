#include <unistd.h>

/**
 * main - start of program
 * Return: always 1
 */

int main(void)

{
char *note = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
write(2, note, 59);

return (1);

}
