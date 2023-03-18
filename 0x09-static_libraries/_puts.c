#include "main.h"

/**
 * _puts - Entry point
 * Description: Prints a string to stdout
 * @s: String data type
 * Return: s
 */

void _puts(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
	_putchar('\n');
}
