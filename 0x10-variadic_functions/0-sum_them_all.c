#include "variadic_functions.h"

/**
 * sum_them_all - returns the sum of all its parameters
 * Description: A function that returns the sum of all of its parameterss
 * @n: number of parameters
 * @'...': variable number of arguments
 *
 * Return: the sum of all parameters.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	int sum = 0;
	unsigned int i;


	if (n == 0)
		return (0);


	va_start(args, n);

	for (i = 0; i < n; i++)
		sum += va_arg(args, int);

	va_end(args);
	return (sum);
}
