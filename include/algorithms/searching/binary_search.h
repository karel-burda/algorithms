#pragma once

#include <stddef.h>

/**
 * Time complexity -- best case: O(1), average and worst case: O(log n)
 * Space complexity -- all cases: O(n)
 */
int searching_binary_search_recursive(const int array[], size_t size, int element);

int searching_binary_search_iterative(const int array[], size_t size, int element);
