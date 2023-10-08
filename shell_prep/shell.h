#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stddef.h>

int _strcspn(char *s, char *reject);
char **get_input(char *);
void c_print(char *str);
int _strlen(char *s);

#endif
