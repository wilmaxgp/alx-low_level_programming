#include "main.h"

/**
 * _strlen - function that returns the length of a string
 *
 * Description: function that returns the length of a string
 *
 * @s: Pointer to the character
 *
 * Return: len
 */

int _strlen(char *s)
{
	int len, index;

	len = 0;

	for (index = 0; *(s + index) != '\0'; index++)
	{
		len++;
	}

	return (len);
}
