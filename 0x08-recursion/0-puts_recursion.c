#include "main.h"

/**
 *_puts_recursion - a standard library that provides a similar function as puts( ) 
 *@s: character input
 *Return: Always void
 *Description: a standard library that provides a similar functuion as puts() followed by a new line.
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')

	{
		_putchar('\n');
		return;
	}

		_putchar (*s);
		_puts_recursion (s + 1);

}
