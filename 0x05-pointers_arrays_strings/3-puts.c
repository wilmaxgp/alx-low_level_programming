#include "main.h"

/**
 * _puts - function that prints a string, followed by a new line
 *
 * Description: function that prints a string, followed by a new line
 *
 * @str: Pointer to the character
 *
 * Return: void
 */

void _puts(char *str)
{
	int index;

	for (index = 0; *(str + index) != '\0'; index++)
	{
		_putchar(*(str + index));
	}
	_putchar('\n');
}
