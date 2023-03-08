#include "main.h"

/**
 * _memcpy - function that copies memory area.
 *
 * Description : function that copies memory area.
 *
 * * @dest: buffer to overwrite
 * @src: buffer to copy
 * @n: number of bytes to overwrite
 *
 * Return: return poiter to start of overwtitten buffer
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *ans = dest;

	while (n--)
	{
		*dest++ = *src++;
	}
	return (ans);
}
