#pragma once

#include <stdbool.h>
#include <stddef.h>

#include "algorithms/error_code.h"

/**
 * Time complexity -- all cases: O(n!)
 * Space complexity -- all cases: O(n!)
 * "permutations" returned has to be freed
 */
error_code string_get_all_permutations(char * string, size_t length, char *** permutations, size_t * permutations_size);
