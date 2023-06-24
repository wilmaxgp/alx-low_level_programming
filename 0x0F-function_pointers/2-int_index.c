#include "function_pointers.h"

/**
 * int_index - a function that searches for an integer
 * Description; a function that searches for an integer
 * @array: pointer to the start of the array
 * @size: the number of elements in the array
 * @cmp:  function pointer
 *
 * Return: void
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && cmp && size > 0)
		
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]) != 0)
				return i;
		}

	return -1;
}
