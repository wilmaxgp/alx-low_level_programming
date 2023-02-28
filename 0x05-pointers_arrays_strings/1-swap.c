#include "main.h"

/**
 * swap_int - function that swaps the values of two integers
 *
 * Description: function that swaps the values of two integers
 *
 * @a: Pointer to the integer
 *
 * @b: Pointer to the integer
 *
 * Return: void
 */

void swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
