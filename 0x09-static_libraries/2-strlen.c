#include "main.h"

/**
 * _strlen - function that returns the length of a string.
 * @s: String pointer
 * Description: function that returns the length of a string.
 * Return: Always 0.
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
