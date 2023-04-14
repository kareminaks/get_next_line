#include <unistd.h>
#include <stdlib.h>
#include "stdio.h"

char *get_next_line(int fd);
size_t index_of(char *start, size_t number, char find);