#include "dog.h"
#include <stdlib.h>
#include <string.h>

/**
 * new_dog - function that creatyes new dog
 * @name: name of dog
 * @age: age of dog
 * @owner: dog owner name
 * Return: pointer to copy of new dog
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;

	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
	{
		return (NULL);
	}
	new_dog->name = malloc(strlen(name));
	new_dog->owner = malloc(strlen(owner));

	if (new_dog->name == NULL || new_dog->owner == NULL)
	{
		return (NULL);
	}

	strcpy(new_dog->name, name);
	new_dog->age = age;
	strcpy(new_dog->owner, owner);

	return (new_dog);
}
