#include "main.h"

/**
 * print_binary - function that prints the binary representation of a number.
 * @n: number of binary to print
 *
 * Description: function that prints the binary representation of a number.
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask;
	int start_printing = 0;

	if (n == 0)
	{
		putchar('0');
		return;
	}

	mask = 1UL << (sizeof(unsigned long int) * 8 - 1);

	while (mask > 0)
	{
		if ((n & mask) || start_printing)
		{
			putchar((n & mask) ? '1' : '0');
			start_printing = 1;
		}
		mask >>= 1;
	}
}
