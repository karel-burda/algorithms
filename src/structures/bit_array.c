#include <stdlib.h>
#include <string.h>

#include "algorithms/error_code.h"
#include "structures/bit_array.h"

const unsigned char bits_in_byte = 8;

static size_t get_byte_index(size_t bit_index)
{
    return bit_index / bits_in_byte;
}

static unsigned char get_bit_position_in_byte(size_t bit_index)
{
    return (unsigned char)(bit_index % bits_in_byte);
}

static size_t get_neccessary_size_in_bytes(size_t bits_needed)
{
    return (bits_needed / bits_in_byte) + (bits_needed % bits_in_byte == 0 ? 0 : 1);
}

static void set_bit(structures_bit_array * bit_array, size_t byte_index, unsigned char bit_position_in_byte, unsigned char value)
{
    const unsigned char shifts_to_left_needed = (unsigned char)(bits_in_byte - bit_position_in_byte - 1);
    const unsigned char byte_with_specific_bit_set = (unsigned char)(1u << shifts_to_left_needed);

    if (value == 1)
    {
        bit_array->array[byte_index] |= byte_with_specific_bit_set;
    }
    else
    {
        bit_array->array[byte_index] &= ~(1u << shifts_to_left_needed);
    }
}

static unsigned char get_bit(structures_bit_array * bit_array, size_t byte_index, unsigned char bit_position_in_byte)
{
    const unsigned char byte = bit_array->array[byte_index];
    const unsigned char shifts_to_right_needed = (unsigned char)(bits_in_byte - bit_position_in_byte - 1);

    return (unsigned char)((byte >> shifts_to_right_needed) & 1u);
}

int structures_bit_array_create(structures_bit_array ** bit_array, size_t size)
{
    int error_code = E_FAILED_ALLOCATION;
    const size_t bytes_needed = get_neccessary_size_in_bytes(size);

    *bit_array = (structures_bit_array *)malloc(bytes_needed);
    if (*bit_array != NULL)
    {
        (*bit_array)->size = bytes_needed;
        (*bit_array)->array = malloc((*bit_array)->size);
        memset((*bit_array)->array, 0, (*bit_array)->size);

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

int structures_bit_array_get(structures_bit_array * bit_array, size_t bit_index, unsigned char * result)
{
    if (bit_array != NULL && result != NULL)
    {
        *result = get_bit(bit_array, get_byte_index(bit_index), get_bit_position_in_byte(bit_index));

        return E_SUCCESS;
    }
    else
    {
        return E_INVALID_INPUT;
    }
}

int structures_bit_array_set(structures_bit_array * bit_array, size_t bit_index, unsigned char value)
{
    if (bit_array != NULL && (value == 0 || value == 1))
    {
        set_bit(bit_array, get_byte_index(bit_index), get_bit_position_in_byte(bit_index), value);

        return E_SUCCESS;
    }
    else
    {
        return E_INVALID_INPUT;
    }
}
