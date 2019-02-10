#include <stddef.h>

#include "algorithms/error_code.h"
#include "algorithms/string/reverse.h"

error_code string_reverse(char * string)
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

        return E_SUCCESS;
    }
    else
    {
        return E_INVALID_INPUT;
    }
}
