#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * malloc_checked - function that allocates memory using malloc
 * @b : bytes size
 *
 * Description: function that allocates memory using malloc.
 *
 * Return: ptr.
 */
void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b); /* locate the size of b using malloc*/

	if (ptr == NULL) /*check if malloc failed */
	{
		exit(98); /*if malloc fails, the malloc_checked function should cause normal process termination with a status value of 98*/
	}
	
	return (ptr);
}
