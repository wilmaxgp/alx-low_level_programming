#include "main.h"
#include <elf.h>

/**
 * print_elf_header - Prints the information in the ELF header.
 * @header: Pointer to the ELF header structure.
 */
void print_elf_header(Elf64_Ehdr *header)
{
	(void)header;
}

/**
 * read_elf_header - Reads the ELF header from the file.
 * @filename: The name of the ELF file to read from.
 * @header: Pointer to the ELF header structure to store the data.
 *
 * Return: 0 on success, -1 on failure.
 */
int read_elf_header(const char *filename, Elf64_Ehdr *header)
{
	int fd;
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		return (-1);
	}
	
	if (read(fd, header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr) ||
        lseek(fd, 0, SEEK_SET) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		close(fd);
		return (-1);
	}
	
	close(fd);
	return (0);
}

/**
 * elf_header - Main function to display the ELF header information.
 * @argc: The number of arguments passed to the program.
 * @argv: Array of pointers to the arguments.
 *
 * Return: 0 on success, 98 on failure.
 */
int elf_header(int argc, char *argv[])
{
	Elf64_Ehdr header;
	
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}
	
	if (read_elf_header(argv[1], &header) == -1)
		return (98);
	
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: %s is not an ELF file\n", argv[1]);
		return (98);
	}
	
	print_elf_header(&header);
	return (0);
}

/**
 * main - Main entry point of the program.
 * @argc: The number of arguments passed to the program.
 * @argv: Array of pointers to the arguments.
 *
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char *argv[])
{
	return (elf_header(argc, argv));
}

