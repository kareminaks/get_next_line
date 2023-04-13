#include "get_next_line.h"
#include "stdio.h"
#include <fcntl.h>

int main() {
    // int fd = open("test_data.txt", O_RDONLY);

    char* str = get_next_line(0);
    while(str) {
        printf(">>> %s\n", str);
        str = get_next_line(0);
    }
    return 0;
}