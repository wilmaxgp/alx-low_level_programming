#include "main.h"

/**
 * _strlen_recursion - function that Concatenates two strings.
 * @dest: Character at start
 * @src: Character at end
 * Description: function that Concatenates two strings.
 * Return: Character that has been concatenated.
 */
char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p != '\0')
	{
		p++;
	}
	while (*src != '\0')
	{
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';
	return (dest);
}
