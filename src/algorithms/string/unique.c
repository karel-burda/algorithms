#include <stddef.h>
#include <string.h>

#include "algorithms/error_code.h"
#include "algorithms/string/unique.h"

static bool has_unique_characters(const char * string, const size_t charset_length) {
    bool characters[charset_length];
    // cannot initialize array with variable lengths like "= { 0 }", so setting its memory manually to all 0s
    memset(&characters, 0, sizeof(characters));

    const char * iterator = string;
    while (*iterator != '\0')
    {
        const char current_character = *iterator;

        if (current_character > 0)
        {
            if (characters[(const unsigned char)current_character] == false)
            {
                characters[(const unsigned char)current_character] = true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            // TODO: handle incorrect char

            return false;
        }

        ++iterator;
    }

    return true;
}

static int string_has_unique_characters(const char * string, bool * result, const size_t charset_length)
{
    if (string != NULL && result != NULL)
    {
        *result = has_unique_characters(string, charset_length);

        return E_SUCCESS;
    }
    else
    {
        return E_INVALID_INPUT;
    }
}

int string_has_unique_characters_ascii(const char * string, bool * result)
{
    return string_has_unique_characters(string, result, 255);
}
