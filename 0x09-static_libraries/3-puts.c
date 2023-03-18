#include "main.h"

/**
 * _puts - function that prints a string, followed by a new line.
 *
 * Description: function that prints a string, followed by a new line, to
 * stdout
 *
 * @s: String pointer
 *
 * Return: void
 */

void _puts(char *s)
{
	int index;

	for (index = 0; *(s + index) != '\0'; index++)
	{
		_putchar(*(s + index));
	}
	_putchar('\n');
}
