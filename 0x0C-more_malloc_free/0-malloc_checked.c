#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * malloc_checked - function that allocates memory using malloc
 * @b : bytes size
 * @ptr : pointer
 * Description: function that allocates memory using malloc.
 *
 * Return: ptr.
 */
void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (ptr == NULL)
		exit(98);
	return (ptr);
}
