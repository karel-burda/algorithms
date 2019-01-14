#pragma once

#include <stddef.h>

struct _burda_structures_bit_array
{
    unsigned char * array;
    size_t size;
};

typedef struct _burda_structures_bit_array bit_array;

int structures_bit_array_create(bit_array ** array, size_t size);

int structures_bit_array_destroy(bit_array ** array);

int structures_bit_array_get(bit_array * array, size_t index, unsigned char * result);

int structures_bit_array_set(bit_array * array, size_t index, unsigned char value);
