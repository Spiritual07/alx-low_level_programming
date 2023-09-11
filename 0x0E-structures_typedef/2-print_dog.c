#include <stdio.h>
#include <string.h>
#include "dog.h"

/**
 * print_dog - function that prints a struct dog
 * struct dog - structure containing dog information
 * @d: pointer to variable declared
 */

void print_dog(struct dog *d)
{
	if (d == NULL)
	{
		return;
	}
	if (d->name == NULL)
	{
		printf("Name: (Nil)\n");
	}
	else
	{
		printf("Name: %s\n", d->name);
	}

	printf("Age: %f\n", d->age);
	
	if (d->owner == NULL)
	{
		printf("Owner: (Nil)\n");
	}
	else
	{
		printf("Owner: %s\n", d->owner);
	}
}
