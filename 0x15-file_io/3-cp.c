#include "main.h"

#define BUF_SIZE 1024

/**
 * error_close - Close file descriptor and print error message.
 * @fd: File descriptor to close.
 * @message: Error message to print.
 */
void error_close(int fd, const char *message)
{
	dprintf(STDERR_FILENO, "%s", message);
	close(fd);
	exit(100);
}

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments passed to the program.
 * @argv: Array of pointers to the arguments.
 *
 * Return: 0 on success, or appropriate error code on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, read_bytes, write_bytes;
	char buffer[BUF_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		error_close(fd_from, "");
	}

	while ((read_bytes = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		write_bytes = write(fd_to, buffer, read_bytes);
		if (write_bytes == -1 || write_bytes != read_bytes)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			error_close(fd_from, "");
		}
	}

	if (read_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		error_close(fd_from, "");
	}

	if (close(fd_from) == -1)
		error_close(fd_to, "Error: Can't close fd ");
	if (close(fd_to) == -1)
		error_close(fd_from, "Error: Can't close fd ");

	return (0);
}
