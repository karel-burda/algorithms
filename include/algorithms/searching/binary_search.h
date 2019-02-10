#pragma once

#include <stddef.h>

#include "algorithms/error_code.h"

/**
 * Time complexity -- best case: O(1), average and worst case: O(log n)
 * Space complexity -- all cases: O(n)
 */
error_code searching_binary_search_recursive(const int array[], size_t size, int element);

error_code searching_binary_search_iterative(const int array[], size_t size, int element);
