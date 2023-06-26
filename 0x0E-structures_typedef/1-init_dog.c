#include "dog.h"

/**
 * init_dog - function that initialize a variable of type struct_dog
 * Description: function that initialize a variable of type struct_dog
 * @d: initialize variable
 * @name: represents the name of the dog
 * @age: represents the age of the dog
 * @owner: represents the name of the dog's owner
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
