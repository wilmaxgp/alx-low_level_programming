#include "main.h"


/**
 * _calloc -  function that allocates memory for an array, using malloc
 * Description: A function that allocates memory for an array, using malloc
 * @nmemb: the number of elements in the array to be allocated
 * @size: the size of the memory to print
 *
 * Return: a pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int total_size;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total_size = nmemb * size;
	ptr = malloc(total_size);

	if (ptr != NULL)
		memset(ptr, 0, total_size);

	return (ptr);
}
