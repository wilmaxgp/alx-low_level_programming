#include "main.h"

/**
 * error_exit - handles error cases and exits
 * @code: error code
 * @message: error message format string
 * @file_name: name of the file causing the error
 * @fd: file descriptor value
 *
 * This function prints an error message, closes file descriptors if needed,
 * and exits the program with the provided error code.
 */
void error_exit(int code, char *message, char *file_name, int fd) {
    dprintf(STDERR_FILENO, message, file_name);
    if (fd != -1)
        close(fd);
    exit(code);
}

/**
 * main - copies content of one file to another
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, otherwise error codes based on specific failures.
 */
int main(int argc, char *argv[]) {
    int file_from, file_to;
    ssize_t nchars, nwr;
    char buf[1024];

    if (argc != 3) {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    file_from = open(argv[1], O_RDONLY);
    file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);

    if (file_from == -1)
        error_exit(98, "Error: Can't read from file %s\n", argv[1], -1);
    if (file_to == -1)
        error_exit(99, "Error: Can't write to %s\n", argv[2], file_from);

    while ((nchars = read(file_from, buf, 1024)) > 0) {
        nwr = write(file_to, buf, nchars);
        if (nwr == -1)
            error_exit(99, "Error: Can't write to %s\n", argv[2], file_from);
    }

    if (nchars == -1)
        error_exit(98, "Error: Can't read from file %s\n", argv[1], file_from);

    if (close(file_from) == -1 || close(file_to) == -1)
        error_exit(100, "Error: Can't close fd\n", "", -1);

    return (0);
}

