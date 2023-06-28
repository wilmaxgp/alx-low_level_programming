#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/**
 * malloc_checked - function that allocates memory using malloc.
 * @b: bytes size
 * Description: function that allocates memory using malloc.  Return: pointer
 * to the allocated memory
 *
 * Return:  a pointer to the allocated memory
 */

void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);

	if (ptr == NULL)
		
		exit(98);

	return (ptr);
}
