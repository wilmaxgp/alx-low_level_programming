#include "main.h"

void print_header_info(Elf64_Ehdr *header) {
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; ++i)
        printf("%02x ", header->e_ident[i]);
    printf("\n");
    printf("  Class:                             ");
    switch (header->e_ident[EI_CLASS]) {
        case ELFCLASSNONE: printf("None\n"); break;
        case ELFCLASS32: printf("ELF32\n"); break;
        case ELFCLASS64: printf("ELF64\n"); break;
        default: printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
    }
    printf("  Data:                              ");
    switch (header->e_ident[EI_DATA]) {
        case ELFDATANONE: printf("None\n"); break;
        case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
        case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
        default: printf("<unknown: %x>\n", header->e_ident[EI_DATA]);
    }
    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
        default: printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
    }
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              ");
    switch (header->e_type) {
        case ET_NONE: printf("None\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default: printf("<unknown: %x>\n", header->e_type);
    }
    printf("  Entry point address:               0x%lx\n", header->e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(98);
    }

    Elf64_Ehdr header;
    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        perror("read");
        close(fd);
        exit(98);
    }

    if (lseek(fd, 0, SEEK_SET) == -1) {
        perror("lseek");
        close(fd);
        exit(98);
    }

    print_header_info(&header);

    close(fd);
    return 0;
}