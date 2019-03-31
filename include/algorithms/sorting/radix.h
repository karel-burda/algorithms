#pragma once

#include <stddef.h>

#include "algorithms/error_code.h"

/**
 * Time complexity -- O(k N), where k is number of digits of highest (or lowest) number
 * Space complexity -- O(N)
 */
error_code sorting_radix(int array[], size_t size);
