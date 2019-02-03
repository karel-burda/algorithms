#include <stddef.h>
#include <inttypes.h>

#include "algorithms/bytes/endianness.h"

static endianness get_endianness()
{
    const u_int16_t number = 1;

    if ((number & 0x1) == 1)
    {
        return E_LITTLE_ENDIAN;
    }
    else if (*((unsigned char *)&number) == 1)
    {
        return E_BIG_ENDIAN;
    }
    else
    {
        return E_UNKNOWN;
    }
}

error_code bytes_get_endiannes(endianness * result)
{
    if (result != NULL)
    {
        *result = get_endianness();

        return E_SUCCESS;
    }
    else
    {
        return E_INVALID_INPUT;
    }
}
