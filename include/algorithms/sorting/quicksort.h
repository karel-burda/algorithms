#pragma once

#include <stddef.h>

#include "algorithms/error_code.h"

/**
 * Time complexity -- best and average case: O(n log n), worst case: O(n ^ 2)
 * Space complexity -- all cases: O(log n)
 */
error_code sorting_quicksort_recursive(int array[], size_t size);
