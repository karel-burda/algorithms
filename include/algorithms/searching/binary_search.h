#pragma once

#include <stddef.h>

/// Time complexity: O (log n)
/// Space complexity: O (n)
int searching_binary_search_recursive(int array[], size_t size, int element);

/// Time complexity: O (log n)
/// Space complexity: O (1)
int searching_binary_search_iterative(int array[], size_t size, int element);
