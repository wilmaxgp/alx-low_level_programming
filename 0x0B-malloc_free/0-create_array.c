#include "main.h"


/**
 * create_array - function that creates an array of chars, and initializes it with a specific char.
 * Description: function that creates an array of chars, and initializes it with a specific char.
 * @size: represents the number of elements the array will have
 * @c: specifies the character to be used for initializing each element of the array
 *
 * Return: a pointer or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
	if (size == 0)
		return NULL;


	char *array = malloc(sizeof(char) * size);
	if (array == NULL)
		return NULL;


	for (unsigned int i = 0; i < size; i++)
	{
		array[i] = c;
	}


	return array;
}
