#include "main.h"

void print_arguments(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
}

int main(int argc, char *argv[])
{
	print_arguments(argc, argv);

	return (0);
}

