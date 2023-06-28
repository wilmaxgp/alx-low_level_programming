#include "main.h"


/**
 * array_range - function that creates an array of integers.
 * Description: function that creates an array of integers.
 * @min: Minimum value
 * @max: Maximum value
 *
 * Return: the pointer to the newly created array
 */
int *array_range(int min, int max)
{
	int i;
	int size;
	int *arr;

	if (min > max)
		return (NULL);

	size = max - min + 1;
	arr = malloc(size * sizeof(int));
	if (arr == NULL)
		return (NULL);
	
	for (i = 0; i < size; i++)
	{
		arr[i] = min++;
	}
	
	return (arr);
}
