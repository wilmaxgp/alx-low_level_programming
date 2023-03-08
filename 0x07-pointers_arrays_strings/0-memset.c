#include "main.h"

/**
 * _memset - function that fills memory with a constant byte.
 *
 * Description : function that fills memory with a constant byte.
 *
 * @s: buffer to overwite
 * @b: constant char to write to buffer
 * @n: number of bytes to overwrite
 *
 * Return: return poiter to start of overwritten buffer
 */

char *_memset(char *s, char b, unsigned int n)
{
	char *p = s;

	while (n-- > 0)
	{
		*p++ = b;
	}
	return (s);
}

