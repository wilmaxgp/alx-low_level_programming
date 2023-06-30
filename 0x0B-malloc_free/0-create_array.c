#include "main.h"


/**
 * create_array - creates an array of chars, and initializes it.
 * Description: function that creates an array of chars, and initializes it .
 * @size: represents the number of elements the array will have
 * @c: character to be used for initializing each element of the array
 *
 * Return: a pointer or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *array;


	if (size == 0)
		return (NULL);


	array = malloc(sizeof(char) * size);
	if (array == NULL)
		return (NULL);


	for (i = 0; i < size; i++)
	{
		array[i] = c;
	}


	return (array);
}
