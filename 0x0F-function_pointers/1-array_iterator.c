#include "stdio.h"
#include "function_pointers.h"

/**
 * array_itrator - executes a function given as a parameter on each element of an array
 * Description: function that executes a function given as a parameter on each element of an array.
 * @array: pointer to the start of the array
 * @size: size of the array
 * @action: function pointer
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;
	
	for (i = 0; i < size; i++)
		action(array[i]);
}
