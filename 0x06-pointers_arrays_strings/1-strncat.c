#include "main.h"
/**
 * _strncat - concatenate two strings using at most n bytes
 *
 * @dest: String to place at the start
 * @src: String to place at the end
 * @n: Number of bytes to concatenate
 *
 * Return: dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (j < n && src[j] != '\0')
	{
	dest[i] = src[j];
	i++;
	j++;
	}
	dest[i] = '\0';
	return (dest);
}

