#include "main.h"

/**
 * _strncat - function that concatenates two strings
 * @dest: String to place at the start
 * @src: String to place at the end
 * @n: Number of bytes to concatenate
 * Description: function that concatenates two strings
 * Return: Concartenated string.
 */
char *_strncat(char *dest, char *src, int n)
{
	char *p = dest;

	/* Find the end of dest */
	while (*p != '\0')
	{
		p++;
	}
	/* Append up to n bytes from src */
	while (*src != '\0' && n-- > 0)
	{
		*p++ = *src++;
	}
	/* Add a null terminator to dest */
	*p = '\0';
	return (dest);
}
