#include <stdlib.h>

#include "algorithms/error_code.h"
#include "structures/bit_array.h"

const size_t bits_in_byte = 8;

int structures_bit_array_create(bit_array ** array, size_t size)
{
    int error_code = E_FAILED_ALLOCATION;
    const size_t bytes_needed = size / bits_in_byte + (size % bits_in_byte);

    *array = (bit_array *)malloc(sizeof(bit_array));
    if (*array != NULL)
    {
        (*array)->size = bytes_needed;
        (*array)->array = malloc((*array)->size);

        if ((*array)->array != NULL)
        {
            error_code = E_SUCCESS;
        }
    }


    return error_code;
}

int structures_bit_array_destroy(bit_array ** array)
{
    free((*array)->array);
    (*array)->array = NULL;

    (*array)->size = 0;

    free(*array);
    *array = NULL;

    return E_SUCCESS;
}
