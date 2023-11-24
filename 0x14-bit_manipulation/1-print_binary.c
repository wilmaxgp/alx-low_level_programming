#include "main.h"

/**
 * print_binary - Prints the binary representation of a number
 * @n: The number to print in binary
 *
 * Description: This function prints the binary representation of a given
 * number without using arrays, malloc, %, or / operators.
 */
void print_binary(unsigned long int n)
{
    if (n == 0)
    {
        _putchar('0');
        return;
    }

    int count = 0;
    int shift = sizeof(unsigned long int) * 8 - 1;

    while ((n >> shift) == 0)
        shift--;

    for (; shift >= 0; shift--)
    {
        count++;
        _putchar((n >> shift) & 1 ? '1' : '0');
    }
}
