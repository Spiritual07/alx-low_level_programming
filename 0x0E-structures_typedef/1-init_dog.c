#include "dog.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * init_dog -  function that initialize a variable of type struct dog
 * struct dog - structure to take dog info
 * @d: pointer to struct dog
 * @name: name of dog
 * @age: age of dog
 * @owner: dog owner name
 */


void init_dog(struct dog *d, char *name, float age, char *owner)
{

	if (d == NULL)
	{
		return;
	}

	d->name = malloc(strlen(name) + 1);
	d->owner = malloc(strlen(owner) + 1);

	if (d->name == NULL || d->owner == NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
		return;
	}
	strcpy(d->name, name);
	d->age = age;
	strcpy(d->owner, owner);
}
