#include "algorithms/error_code.h"
#include "algorithms/string/strlen.h"

int string_strlen(const char * string, size_t * length)
{
    if (string != NULL && length != NULL)
    {
        *length = 0;
        const char *character = string;

        while (*character != '\0')
        {
            ++(*length);
            ++character;
        }

        return E_SUCCESS;
    }
    else
    {
        return E_INVALID_INPUT;
    }
}
