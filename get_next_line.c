#include "get_next_line.h"

void ft_memcpy(char* dst, char* src, size_t len) {
    size_t i = 0;
    while(i < len) {
        dst[i] = src[i];
        i++;
    }
}

char *get_next_line(int fd) {
    size_t size = 8;
    size_t bytes_read = 0;
    char* buf = malloc(size);
    size_t index_of_newline; 

    while (1) {
        size_t read_now = read(fd, buf + bytes_read, size - bytes_read);
        if (!read_now) {
            break;
        }
        index_of_newline = index_of(buf + bytes_read, read_now, '\n');
        if (index_of_newline < read_now) {
            bytes_read += index_of_newline;
            break;
        }

        bytes_read += read_now;
        if (bytes_read == size) {
            char* new_buf = malloc(size * 2);
            ft_memcpy(new_buf, buf, size);
            free(buf);
            buf = new_buf;
            size = size * 2;
        }
    }

    if (bytes_read == size) {
         char* new_buf = malloc(size + 1);
        ft_memcpy(new_buf, buf, size);
        free(buf);
        buf = new_buf;
        size = size + 1;
    }
    buf[bytes_read] = 0;
    
    return buf;
} 