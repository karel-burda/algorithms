#include <stddef.h>
#include <inttypes.h>
#include <sys/types.h>

#include "algorithms/bytes/endianness.h"

static endianness get_endianness() __attribute__ ((optnone))
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

error_code bytes_get_endianness(endianness * result)
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
