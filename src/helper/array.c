#include <stdio.h>

#include "helper/array.h"

void helper_print_array(int * array, size_t start_index, size_t end_index)
{
    if (array != NULL) {
        for (size_t i = start_index; i <= end_index; ++i)
        {
            printf("%d", array[i]);

            if (i < end_index)
            {
                printf(",");
            }
        }

        printf("\n");
    }
}
