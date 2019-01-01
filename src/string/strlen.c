#include "algorithms/string/strlen.h"

size_t string_strlen(const char * string)
{
    size_t length = 0;

    if (string != NULL)
    {
        const char *character = string;

        while (*character != '\0')
        {
            ++length;
            ++character;
        }
    }

    return length;
}
