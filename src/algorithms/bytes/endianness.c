#include <stddef.h>
#include <inttypes.h>
#include <sys/types.h>

#include "algorithms/bytes/endianness.h"

#if defined(__clang__) || defined(__APPLE__)
__attribute__ ((optnone)) static endianness get_endianness()
#elif defined(__GNUC__) || defined(__GNUG__)
static endianness __attribute__((optimize("O0"))) get_endianness()
#else
static endianness get_endianness()
#endif
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
