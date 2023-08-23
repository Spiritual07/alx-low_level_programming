#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main -  program that generates random valid
 * passwords for the program 101-crackme.
 * Return: 0 (success)
 */

int main(void)
{
    int random_num;
    int loop_counter;
    int summation = 2772;
    
    // seed the random number generator with current system time
    srand(time(NULL));

    // loop until summation > 122
    for (loop_counter = 0; summation > 122; loop_counter++)
    {
        // Generate a random number in the range 1 - 125 (Inclusive)
        random_num = (rand() % 125) + 1;
        // Print the character corresponding to ASCII value of random_num
        putchar(random_num);
        // Deduct random_num from summation
        summation -= random_num;
    }
    // Print the remaining ASCII character
    putchar(summation);
    
    return 0;
}
