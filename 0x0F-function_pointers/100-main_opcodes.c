#include "function_pointers.h"

/**
 * print_opcodes -  prints the opcodes of its own main function
 *
 * @argc: The number of arguments passed to the program
 * @argv: An array of pointers to the arguments
 */
void print_opcodes(int num_bytes)
{
	unsigned char *ptr = (unsigned char *)print_opcodes;
	int i;
	for (i = 0; i < num_bytes; i++)
	{
		printf("%02x ", *(ptr + i));
	}
	printf("\n");
}


int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	int num_bytes = atoi(argv[1]);
	if (num_bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	print_opcodes(num_bytes);

	return (0);
}
