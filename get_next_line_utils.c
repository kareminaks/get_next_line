#include "get_next_line.h"

size_t index_of(char *start, size_t number, char find)
{
    size_t checked =0;
    while (checked!=number)
    {
        if (start[checked]== find)
            return(checked);
        checked++;
    }
    return(number);
}

