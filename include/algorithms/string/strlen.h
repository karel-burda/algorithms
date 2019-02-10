#pragma once

#include <stddef.h>

#include "algorithms/error_code.h"

/**
 * Time complexity -- all cases: O(n)
 * Space complexity -- all cases: O(n)
 */
error_code string_strlen(const char * string, size_t * length);
