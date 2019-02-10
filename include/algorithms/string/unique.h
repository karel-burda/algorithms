#pragma once

#include <stdbool.h>

#include "algorithms/error_code.h"

/**
 * Time complexity -- all cases: O(n)
 * Space complexity -- all cases: O(1)
 */
error_code string_has_unique_characters_ascii(const char * string, bool * result);
