#pragma once

#include <stdbool.h>
#include <stddef.h>

#include "algorithms/error_code.h"

/**
 * Time complexity --  all cases: O(sqrt(n))
 * Space complexity -- all cases: 1
 */
error_code number_is_prime_using_division(size_t number, bool * is_prime);
