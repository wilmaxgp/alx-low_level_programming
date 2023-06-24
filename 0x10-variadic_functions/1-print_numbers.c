#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_numbers - prints number followed by a new line
 * Description: function that prints number followed by a new line.
 * @separator: string to be printed between numbers
 * @n: the number of integer passed to the function
 * @'...': variable argument
 *
 * Return: void
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	int num;
	
	va_start(args, n);
	
	for (i = 0; i < n; i++)
	{
		num = va_arg(args, int);
		printf("%d", num);
		
		if (separator != NULL && i < n - 1)
			printf("%s", separator);
	}
	
	va_end(args);
	
	printf("\n");
}
