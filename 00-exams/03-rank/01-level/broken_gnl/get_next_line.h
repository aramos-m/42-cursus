#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <sys/types.h> // size_t
#include <stdlib.h> // malloc, free
#include <unistd.h> // read, close
#include <fcntl.h> // "file control"; open, O_RDONLY
#include <stdio.h> // printf

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char *get_next_line(int fd);

#endif