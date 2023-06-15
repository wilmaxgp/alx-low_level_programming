#include "main.h"

/**
 * _strcpy - function that prints Copies string pointed to by src.
 * @dest: Destination String
 * @src: Source String
 * Description: function that prints Copies string pointed to by src.
 * Return: Always 0
 */
char *_strcpy(char *dest, char *src)
{
	char *p = dest;

	while (*src != '\0')
	{
		*p++ = *src++;
	}
	*p = '\0';
	return (dest);
}
