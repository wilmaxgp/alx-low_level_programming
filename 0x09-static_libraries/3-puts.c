#include "main.h"

/**
 *_puts - function that prints a string, followed by a new line.
 *@s: character input
 *Return: Always void
 *Description: function that prints a string, followed by a new line.
 */
void _puts(char *s)
{
	if (*s == '\0')

	{
		_putchar('\n');
		return;
	}

		_putchar(*s);
		_puts(s + 1);

}
