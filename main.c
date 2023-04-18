#include "get_next_line.h"
#include "stdio.h"
#include <fcntl.h>

int main() {
    int fd = open("test_data.txt", O_RDONLY);
    close(fd);

    char* str = get_next_line(fd);
    while(str) {
        printf(">>> %s\n", str);
        str = get_next_line(fd);
    }
    return 0;
}