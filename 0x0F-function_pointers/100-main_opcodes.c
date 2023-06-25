#include "function_pointers.h"

/**
 * main -  prints the opcodes of its own main function
 *
 * @argc: The number of arguments passed to the program
 * @argv: An array of pointers to the arguments
 * main function's opcodes to be printed
 * Return: main
 */
int main(int argc, char *argv[])
{
	int num_bytes, i;
	char *address;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	address = (char *)main;

	for (i = 0; i < num_bytes; i++)
	{
		printf("%02hhx%c", address[i], i < num_bytes - 1 ? ' ' : '\n');
	}
	return (0);
}
