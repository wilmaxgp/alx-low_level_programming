#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output.
 * @filename: Name of the file to read.
 * @letters: Number of letters it should read and print.
 * Return: The actual number of letters it could read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters) {
    int fd;
    ssize_t bytes_read;
    char *buf;

    if (!filename)
        return 0;

    buf = malloc(sizeof(char) * letters);
    if (!buf)
        return 0;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        free(buf);
        return 0;
    }

    bytes_read = read(fd, buf, letters);
    if (bytes_read == -1) {
        free(buf);
        close(fd);
        return 0;
    }

    write(STDOUT_FILENO, buf, bytes_read);

    free(buf);
    close(fd);

    return bytes_read;
}

/**
 * create_file - Creates a file and writes text content to it.
 * @filename: Name of the file to create.
 * @text_content: Content to write into the file.
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content) {
    int fd, len, bytes_written;

    if (!filename)
        return -1;

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
    if (fd == -1)
        return -1;

    if (text_content) {
        len = 0;
        while (text_content[len] != '\0')
            len++;

        bytes_written = write(fd, text_content, len);
        if (bytes_written == -1) {
            close(fd);
            return -1;
        }
    }

    close(fd);

    return 1;
}

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: Name of the file to append to.
 * @text_content: Content to append to the file.
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content) {
    int fd, len, bytes_written;

    if (!filename)
        return -1;

    fd = open(filename, O_WRONLY | O_APPEND);
    if (fd == -1)
        return -1;

    if (text_content) {
        len = 0;
        while (text_content[len] != '\0')
            len++;

        bytes_written = write(fd, text_content, len);
        if (bytes_written == -1) {
            close(fd);
            return -1;
        }
    }

    close(fd);

    return 1;
}

/**
 * print_error - Prints an error message and exits with a given code.
 * @code: The exit code.
 * @message: The error message to print.
 * @filename: The name of the file associated with the error.
 * @fd: The file descriptor associated with the error (-1 if not applicable).
 */
void print_error(int code, const char *message, const char *filename, int fd) {
    if (fd != -1)
        dprintf(STDERR_FILENO, "%s %s fd %d\n", message, filename, fd);
    else
        dprintf(STDERR_FILENO, "%s %s\n", message, filename);
    exit(code);
}

/**
 * open_files - Opens two files for reading and writing operations.
 * @file_from: The source file.
 * @file_to: The destination file.
 * @fd_from: Pointer to store the file descriptor for the source file.
 * @fd_to: Pointer to store the file descriptor for the destination file.
 */
void open_files(const char *file_from, const char *file_to, int *fd_from, int *fd_to) {
    *fd_from = open(file_from, O_RDONLY);
    if (*fd_from == -1)
        print_error(98, "Error: Can't read from file", file_from, -1);

    *fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
    if (*fd_to == -1)
        print_error(99, "Error: Can't write to file", file_to, -1);
}

/**
 * copy_files - Copies content from one file to another.
 * @fd_from: File descriptor of the source file.
 * @fd_to: File descriptor of the destination file.
 */
void copy_files(int fd_from, int fd_to) {
    ssize_t bytes_read, bytes_written;
    char buffer[BUF_SIZE];

    while ((bytes_read = read(fd_from, buffer, BUF_SIZE)) > 0) {
        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written != bytes_read)
            print_error(99, "Error: Can't write to file", "", fd_to);
    }

    if (bytes_read == -1)
        print_error(98, "Error: Can't read from file", "", fd_from);
}

/**
 * close_files - Closes two files.
 * @fd_from: File descriptor of the source file.
 * @fd_to: File descriptor of the destination file.
 * @file_from: The name of the source file.
 * @file_to: The name of the destination file.
 */
void close_files(int fd_from, int fd_to, const char *file_from, const char *file_to) {
    if (close(fd_from) == -1) {
        print_error(100, "Error: Can't close fd", file_from, fd_from);
    }

    if (close(fd_to) == -1) {
        print_error(100, "Error: Can't close fd", file_to, fd_to);
    }
}

/**
 * main - Entry point of the program.
 * @argc: Number of arguments.
 * @argv: Array containing the arguments.
 * Return: 0 on success, 97 on incorrect number of arguments, and other error codes accordingly.
 */
int main(int argc, char *argv[]) {
    const char *file_from = argv[1];
    const char *file_to = argv[2];
    int fd_from, fd_to;


    	if (argc != 3) {
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        return 97;
    }


    open_files(file_from, file_to, &fd_from, &fd_to);
    copy_files(fd_from, fd_to);
    close_files(fd_from, fd_to, file_from, file_to);

    return 0;
}
