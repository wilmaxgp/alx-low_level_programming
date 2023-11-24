#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index
 * @n: Pointer to an unsigned long int
 * @index: Index of the bit to set (starting from 0)
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{	unsigned long int mask;
	
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	
	mask = 1UL << index;
	*n = *n & (~mask);
	
	return (1);
}
