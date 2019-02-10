#include <stddef.h>

#include "algorithms/error_code.h"
#include "algorithms/bits/bits.h"

static const unsigned char bits_in_byte = 8;

static int find_number_of_one_bits(int number, unsigned char * one_bits)
{
    *one_bits = 0;
    const unsigned char bit_shits = sizeof(number) * bits_in_byte;
    unsigned char i = 0;

    while (i < bit_shits)
    {
        if ((number & 0x1) == 1)
        {
            ++(*one_bits);
        }

        number >>= 1;
        ++i;
    }

    return E_SUCCESS;
}

int bits_find_number_of_one_bits(int number, unsigned char * one_bits)
{
    if (one_bits != NULL)
    {
       return find_number_of_one_bits(number, one_bits);
    }
    else
    {
        return E_INVALID_INPUT;
    }
}
