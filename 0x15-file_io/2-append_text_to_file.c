#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - Appends text_content to the end of a file.
 * @filename: The name of the file to which to append the text.
 * @text_content: The NULL-terminated string to add at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, text_len, bytes_written;
	
	if (filename == NULL)
		return (-1);
	
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	
	if (text_content != NULL)
	{
		for (text_len = 0; text_content[text_len]; text_len++)
			continue;
		
		bytes_written = write(fd, text_content, text_len);
		
		if (bytes_written == -1 || bytes_written != text_len)
		{
			close(fd);
			return (-1);
		}
	}
	
	close(fd);
	return (1);
}
