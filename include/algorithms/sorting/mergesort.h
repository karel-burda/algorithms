#pragma once

#include <stddef.h>

#include "algorithms/error_code.h"

/**
 * Time complexity -- all cases: O(n log n)
 * Space complexity -- all cases: O(n)
 */
error_code sorting_mergesort(int array[], size_t size);
