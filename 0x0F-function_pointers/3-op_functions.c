#include "3-calc.h"
#include "stdio.h"

/**
 * op_add - function adds two integer
 * 
 * @a: 1st integer
 * @b: 2nd integer
 */
int op_add(int a, int b)
{
	return (a + b);
}


/**
 * op_sub - function subtract two integer
 *
 * @a: 1st integer
 * @b: 2nd integer
 */
int op_sub(int a, int b)
{
	return (a - b);
}


/**
 * op_mul - function multiply two integer
 *
 * @a: 1st integer
 * @b: 2nd integer
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - function divides two integer
 *
 * @a: 1st integer
 * @b: 2nd integer
 */
int op_div(int a, int b)
{
	return (a / b);
}


/**
 * op_mod - function the returns the remainder of a division
 * @a: 1st integer
 * b@: 2nd integer
 */
int op_mod(int a, int b)
{
	return (a % b);
}