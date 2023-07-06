#include "main.h"


/**
 * _realloc - function that reallocates a memory block using malloc and free
 * Description: function that reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: The size, in bytes, of the allocated space for ptr
 * @new_size: The new size, in bytes, of the new memory block
 *
 * Return: void
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		return (malloc(new_size));
	}


	if (new_size == old_size)
	{
		return (ptr);
	}

	new_ptr = malloc(new_size);
	if (new_ptr != NULL)
	{
		unsigned int copy_size = old_size < new_size ? old_size : new_size;

		imemcpy(new_ptr, ptr, copy_size);
		free(ptr);
	}

	return (new_ptr);
}

