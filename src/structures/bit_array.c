#include <stdlib.h>

#include "algorithms/error_code.h"
#include "structures/bit_array.h"

const size_t bits_in_byte = 8;

int structures_bit_array_create(structures_bit_array ** bit_array, size_t size)
{
    int error_code = E_FAILED_ALLOCATION;
    const size_t bytes_needed = size / bits_in_byte + (size % bits_in_byte);

    *bit_array = (structures_bit_array *)malloc(sizeof(bit_array));
    if (*bit_array != NULL)
    {
        (*bit_array)->size = bytes_needed;
        (*bit_array)->array = malloc((*bit_array)->size);

        if ((*bit_array)->array != NULL)
        {
            error_code = E_SUCCESS;
        }
    }


    return error_code;
}

int structures_bit_array_destroy(structures_bit_array ** bit_array)
{
    if (bit_array != NULL && *bit_array != NULL) {
        free((*bit_array)->array);
        (*bit_array)->array = NULL;

        (*bit_array)->size = 0;

        free(*bit_array);
        *bit_array = NULL;

        return E_SUCCESS;
    }
    else
    {
        return E_INVALID_INPUT;
    }
}

int structures_bit_array_get(structures_bit_array * bit_array, size_t index, unsigned char * result)
{
    if (bit_array != NULL)
    {
        const unsigned char byte_index = index / bits_in_byte;
        const unsigned char byte = bit_array->array[byte_index];
        const unsigned char bit_position_in_byte = index % bits_in_byte;
        const unsigned char shifts_to_right_needed = bits_in_byte - bit_position_in_byte - 1;

        *result = byte >> shifts_to_right_needed & 1;

        return E_SUCCESS;
    }
    else
    {
        return E_INVALID_INPUT;
    }
}

int structures_bit_array_set(structures_bit_array * bit_array, size_t index, unsigned char value)
{
    if (bit_array != NULL)
    {
        // TODO: extract this to function
        const unsigned char byte_index = index / bits_in_byte;
        const unsigned char bit_position_in_byte = index % bits_in_byte;
        const unsigned char shifts_to_left_needed = bits_in_byte - bit_position_in_byte - 1;

        bit_array->array[byte_index] |= (1 << shifts_to_left_needed);

        return E_SUCCESS;
    }
    else
    {
        return E_INVALID_INPUT;
    }
}
