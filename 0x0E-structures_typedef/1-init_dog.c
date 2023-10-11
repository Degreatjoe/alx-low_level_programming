#include <stdio.h>
#include "dog.h"
/**
 * init_dog - initialising the dog's information
 * @d: pointer to struct dog
 * @name: name to be initialized
 * @age: the age of the dog
 * @owner: the name of the owner of the dfog
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = name;
	d->age = age;
	d->owner = owner;
}
