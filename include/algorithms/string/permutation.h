#pragma once

#include <stdbool.h>
#include <stddef.h>

#include "algorithms/error_code.h"

error_code string_are_permutations(const char * first, const char * second, size_t length, bool * permutations);

error_code string_get_all_permutations(char * string, size_t length, char *** permutations, size_t * permutations_size);
