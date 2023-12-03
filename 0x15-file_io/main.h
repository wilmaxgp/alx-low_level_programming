#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <elf.h>

#define BUF_SIZE 1024
#define PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void print_error(int code, const char *message, const char *filename, int fd);
void open_files(const char *file_from, const char *file_to, int *fd_from, int *fd_to);
void copy_files(int fd_from, int fd_to);
void close_files(int fd_from, int fd_to, const char *file_from, const char *file_to);
int main(int argc, char *argv[]);

#endif
