#include "get_next_line.h"

void ft_memcpy(char* dst, char* src, size_t len) {
    size_t i = 0;
    while(i < len) {
        dst[i] = src[i];
        i++;
    }
}

void try_reallocate(char** buf, size_t* size, size_t bytes_read) {
    if (bytes_read == *size) {
        char* new_buf = malloc(*size + 8);
        ft_memcpy(new_buf, *buf, *size);
        free(*buf);
        *buf = new_buf;
        *size = *size + 8;
    }
}

char* cut(char* src, size_t len) {
    char * res = malloc(len + 1);
    ft_memcpy(res, src, len);
    res[len] = 0;
    return res;
}

char *get_next_line(int fd) {
    size_t size = 8;
    size_t bytes_read = 0;
    char* buf = malloc(size);
    size_t index_of_newline; 

    static char stash[8];
    static size_t stash_size = 0;

    index_of_newline = index_of(stash, stash_size, '\n');
    if (index_of_newline < stash_size) {
        ft_memcpy(stash, stash + index_of_newline + 1, stash_size - index_of_newline - 1);
        ft_memcpy(buf, stash, index_of_newline + 1);
        buf[index_of_newline + 1] = 0;
        stash_size = stash_size - index_of_newline - 1;
        return buf;
    }

    ft_memcpy(buf, stash, stash_size);
    bytes_read = stash_size;
    stash_size = 0;
    try_reallocate(&buf, &size, bytes_read);

    while (1) {
        size_t read_now = read(fd, buf + bytes_read, size - bytes_read);
        if (!read_now) {
            break;
        }
        index_of_newline = index_of(buf + bytes_read, read_now, '\n');
        if (index_of_newline < read_now) {
            bytes_read += index_of_newline + 1;

            stash_size = read_now - (index_of_newline + 1);
            ft_memcpy(stash, buf + bytes_read, stash_size);
            break;
        }

        bytes_read += read_now;
        try_reallocate(&buf, &size, bytes_read);
    }

    if (!bytes_read) {
        return 0;
    }

    try_reallocate(&buf, &size, bytes_read);
    buf[bytes_read] = 0;
    
    return buf;
} 