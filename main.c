#include "get_next_line.h"
#include "stdio.h"
#include <fcntl.h>

int main() {
    int fd = 0;// open("test_data.txt", O_RDONLY);

    char* str = get_next_line(fd);
    while(str) {
        printf(">>> %s\n", str);
        str = get_next_line(fd);
    }
    return 0;
}