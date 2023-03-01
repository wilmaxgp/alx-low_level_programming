#include "main.h"

/**
 * puts2 - function that prints string
 *
 * Description: function that prints every other character
 * starting with the first character, followed by a new line
 *
 * @str: Pointer to the character
 *
 * Return: void
 */

void puts2(char *str)
{
	int index;

	for (index = 0; *(str + index) != '\0'; index++)
	{
		if (*(str + index) == '\0')
		{
			break;
		}
		if (index % 2 == 0)
		{
			_putchar(*(str + index));
		}
	}
	_putchar('\n');
}
