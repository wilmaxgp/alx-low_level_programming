#include "3-calc.h"
#include "stdio.h"
#include "stdlib.h"

/**
 * main - entry point of the program
 *
 * @argc: argument count
 * @argv: argument vector
 */
int main(int argc, char *argv[])
{
	if (argc >= 4)
		char *operator = argv[1];
		int a = atoi(argv[2]);
        	int b = atoi(argv[3]);

		int (*func_ptr)(int, int) = get_op_func(operator);

		if (func_ptr != NULL)
			 int result = func_ptr(a, b);
			 printf("Result: %d\n", result);

	else
		printf("Error\n");

	return (0);
}
