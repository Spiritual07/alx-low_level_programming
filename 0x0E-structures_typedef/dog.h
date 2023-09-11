#ifndef DOG_H
#define DOG_H

/**
 * struct dog - structure to keep record of a dog.
 * @name: name of dog
 * @age: dog age
 * @owner: owner of dog
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);


#endif
