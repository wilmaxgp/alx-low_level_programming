#include "main.h"

/**
 *_puts_recursion - function that fills memory with a constant byte
 * @s: buffer to overwite
 * @b: constant char to write to buffer
 * @n: number of bytes to overwrite
 *Return: Always void
 *Description: function that fills memory with a constant byte
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int index;

	for (index = 0; index < n; index++)
	{
		*(s + index) = b;
	}

	return (s);
}
