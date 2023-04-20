#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main() {
    int fd = open("test_data.txt", O_RDONLY);
    char* str = get_next_line(fd);
    while(str) {
        printf(">>> %s\n", str);
        free(str);
        str = get_next_line(fd);
    }
    close(fd);
    return 0;
}