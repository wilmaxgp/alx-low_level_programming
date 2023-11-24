#include "main.h"

/**
 * print_binary - Prints the binary representation of an unsigned long int
 * @n: The number to be printed in binary
 *
 * Description: This function prints the binary representation of a number
 * without using arrays, %, / operators, or malloc.
 */
void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);

	_putchar((n & 1) + '0');
}
