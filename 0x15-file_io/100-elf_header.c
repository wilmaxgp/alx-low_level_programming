#include "main.h"

/**
 * print_elf_info - Print information about an ELF header.
 * @header: Pointer to the ELF header structure
 *
 * This function prints various information about an ELF header structure.
 */
void print_elf_info(Elf32_Ehdr *header)
{
    int i;

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; ++i)
    {
        printf("%02x", header->e_ident[i]);
        if (i < EI_NIDENT - 1)
            printf(" ");
        else
            printf("\n");
    }

    printf("  Class:                             ");
    switch (header->e_ident[EI_CLASS])
    {
    case ELFCLASSNONE:
        printf("None\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    }

    printf("  Data:                              ");
    switch (header->e_ident[EI_DATA])
    {
    case ELFDATANONE:
        printf("None\n");
        break;
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    }

    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);

    // Correctly display the OS/ABI field
    printf("  OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI])
    {
    case 0:
        printf("UNIX - System V\n");
        break;
    case 2:
        printf("UNIX - NetBSD\n");
        break;
    case 6:
        printf("UNIX - Solaris\n");
        break;
    case 53:
        printf("<unknown: 53>\n");
        break;
    default:
        printf("<unknown>\n");
        break;
    }

    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    switch (header->e_type)
    {
    case ET_NONE:
        printf("None\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    }

    printf("  Entry point address:               0x%x\n", header->e_entry);
}

/**
 * main - Entry point of the program
 *
 * This function demonstrates the usage of print_elf_info
 * by creating an ELF header structure with example data
 * and printing its information.
 *
 * Return: Always 0
 */
int main(void)
{
    // Example ELF header data
    unsigned char elf_header_data[] = {
        0x7f, 0x45, 0x4c, 0x46, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x03, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x74, 0x80, 0x04, 0x08, 0x34, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x34, 0x00, 0x20, 0x00,
        0x01, 0x00, 0x00, 0x00
    };

    // Create ELF header struct and populate with example data
    Elf32_Ehdr elf_header;
    for (int i = 0; i < sizeof(elf_header_data); ++i)
    {
        ((unsigned char *)&elf_header)[i] = elf_header_data[i];
    }

    // Print ELF header information
    print_elf_info(&elf_header);

    return 0;
}
