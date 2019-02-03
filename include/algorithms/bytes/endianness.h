#pragma once

#include "algorithms/error_code.h"

enum _burda_algorithms_endianness
{
    E_BIG_ENDIAN = 0,
    E_LITTLE_ENDIAN = 1,
    E_UNKNOWN = -1
};

typedef enum _burda_algorithms_endianness endianness;

error_code bytes_get_endiannes(endianness * result);
