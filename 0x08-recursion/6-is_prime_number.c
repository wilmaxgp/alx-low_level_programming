#include "main.h"

int is_prime_check(int n, int divisor);

/**
 * is_prime_number - Check if a number is prime
 * @n: The number to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	if (n == 2)
		return (1);
	if (n % 2 == 0)
		return (0);

	return (is_prime_check(n, 3));
}

/**
 * is_prime_check - checker function to check if a number is prime
 * @n: The number to check
 * @divisor: The divisor to check against n
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_check(int n, int divisor)
{
	if (n % divisor == 0)
		return (0);
	if (divisor * divisor > n)
		return (1);

	return (is_prime_check(n, divisor + 2));
}

