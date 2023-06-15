#include "main.h"

/**
 * _strncpy - function that copies a string.
 * @dest: String to place at the start
 * @src: String to place at the end
 * @n: Number of bytes to concatenate
 *Description: function that copies a string.
 * Return: Always 0.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}
