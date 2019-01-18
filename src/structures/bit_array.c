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
    if (array != NULL && *array != NULL) {
        free((*array)->array);
        (*array)->array = NULL;

        (*array)->size = 0;

        free(*array);
        *array = NULL;

        return E_SUCCESS;
    }
    else
    {
        return E_INVALID_INPUT;
    }
}

int structures_bit_array_get(bit_array * array, size_t index, unsigned char * result)
{
    if (array != NULL)
    {
        const unsigned char byte_index = index / bits_in_byte;
        const unsigned char byte = array->array[byte_index];
        const unsigned char bit_position_in_byte = index % bits_in_byte;
        const unsigned char shifts_to_right_needed = bits_in_byte - bit_position_in_byte - 1;

        *result = byte >> shifts_to_right_needed & 0x1;

        return E_SUCCESS;
    }
    else
    {
        return E_INVALID_INPUT;
    }
}
