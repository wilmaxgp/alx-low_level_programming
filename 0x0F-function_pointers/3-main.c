#include "3-calc.h"

/**
 * main - entry point of the program
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: main
 */
int main(int argc, char *argv[])
{
	int result;
	int num1, num2;
	int (*operation)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}

	operation = get_op_func(argv[2]);

	if (operation == NULL)
	{
		printf("Error\n");
		return (99);
	}
	
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	
	
	if ((*argv[2] == '/' || *argv[2] == '%') && num2 == 0)
	{
		printf("Error\n");
		return (100);
	}
	
	result = operation(num1, num2);
	printf("%d\n", result);
	return (0);
}
