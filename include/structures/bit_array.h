#pragma once

#include <stddef.h>

#include "algorithms/error_code.h"

/* Example with bit array with size of 19, totally occupies 3 bytes
 * |0|1|2|3|4|5|6|7|  |8|9|10|11|12|13|14|15|  |16|17|18|0|0|0|0|0|
 * <--------------->  <--------------------->  <------------------>
 *       1 byte                1 byte                 1 byte
 */
struct _burda_structures_bit_array
{
    unsigned char * array;
    size_t size;
};

typedef struct _burda_structures_bit_array structures_bit_array;

/**
 * Time complexity -- all cases: O(1)
 * Space complexity -- all cases: O(n)
 */
error_code structures_bit_array_create(structures_bit_array ** bit_array, size_t size);

/**
 * Time complexity -- all cases: O(1)
 * Space complexity -- all cases: O(1)
 */
error_code structures_bit_array_destroy(structures_bit_array ** bit_array);

/**
 * Time complexity -- all cases: O(1)
 * Space complexity -- all cases: O(1)
 */
error_code structures_bit_array_get(structures_bit_array * bit_array, size_t bit_index, unsigned char * result);

/**
 * Time complexity -- all cases: O(1)
 * Space complexity -- all cases: O(1)
 */
error_code structures_bit_array_set(structures_bit_array * bit_array, size_t bit_index, unsigned char value);
