#include <stddef.h>

#include "algorithms/string/reverse.h"

int string_reverse(char * string)
{
    if (string != NULL && *string != '\0')
    {
        char * start = string;
        char * end = start;

        while (*end != '\0')
        {
            ++end;
        }
        --end;

        while (start < end)
        {
            const char temp = *start;
            *start = *end;
            *end = temp;

            ++start;
            --end;
        }

        return 0;
    }
    else
    {
        return -1;
    }
}
