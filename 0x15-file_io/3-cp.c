#include "main.h"

#define BUFFER_SIZE 1024

void print_error(int code, const char *message, const char *filename, int fd) {
    dprintf(STDERR_FILENO, "%s: %s", message, filename);
    if (fd != -1)
        dprintf(STDERR_FILENO, " fd %d", fd);
    dprintf(STDERR_FILENO, "\n");
    exit(code);
}

void open_files(const char *file_from, const char *file_to, int *fd_from, int *fd_to) {
    *fd_from = open(file_from, O_RDONLY);
    if (*fd_from == -1)
        print_error(98, "Error: Can't read from file", file_from, -1);

    *fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (*fd_to == -1)
        print_error(99, "Error: Can't write to file", file_to, -1);
}

void copy_files(int fd_from, int fd_to) {
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written != bytes_read)
            print_error(99, "Error: Can't write to file", "", fd_to);
    }

    if (bytes_read == -1)
        print_error(98, "Error: Can't read from file", "", fd_from);
}

void close_files(int fd_from, int fd_to, const char *file_from, const char *file_to) {
    if (close(fd_from) == -1) {
        print_error(100, "Error: Can't close fd", file_from, fd_from);
    }

    if (close(fd_to) == -1) {
        print_error(100, "Error: Can't close fd", file_to, fd_to);
    }
}

int main(int argc, char *argv[]) {
    const char *file_from;
    const char *file_to;
    int fd_from, fd_to;

    if (argc != 3) {
        dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
        return 97;
    }

    file_from = argv[1];
    file_to = argv[2];

    open_files(file_from, file_to, &fd_from, &fd_to);
    copy_files(fd_from, fd_to);
    close_files(fd_from, fd_to, file_from, file_to);

    return 0;
}
