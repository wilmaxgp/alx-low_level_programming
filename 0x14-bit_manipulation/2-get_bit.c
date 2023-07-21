#include "main.h"

/**
 * get_bit - function that returns the value of a bit at a given index.
 * @n: number to retrieve the bit
 * @index: the index of the bit to retrieve.
 *
 * Description: function that returns the value of a bit at a given index.
 * Return: the value of the bit at index index or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	mask = 1UL << index;

	return ((n & mask) ? 1 : 0);
}
