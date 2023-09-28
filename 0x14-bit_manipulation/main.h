#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdlib.h>

int clear_bit(unsigned long int *n, unsigned int index);
int set_bit(unsigned long int *n, unsigned int index);
int get_bit(unsigned long int n, unsigned int index);
unsigned int binary_to_uint(const char *b);
int _putchar(char c);
void print_binary(unsigned long int n);

#endif
