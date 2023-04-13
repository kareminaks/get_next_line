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

    while (1) {
        size_t read_now = read(fd, buf + bytes_read, size - bytes_read);
        if (!read_now) {
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
    
    return buf;
} 