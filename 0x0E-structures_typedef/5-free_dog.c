#include "dog.h"

/**
 * free_dog - function that frees dogs
 * Description: function that frees dogs
 * @d: pointer to the dog struct to free
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
	{
		return;
	}


	free(d->name);
	free(d->owner);
	free(d);
}
