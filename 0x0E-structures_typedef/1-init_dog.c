#include "dog.h"

/**
 * init_dog - function that initialize a variable of type struct_dog
 * Description: function that initialize a variable of type struct_dog
 * @d:
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
