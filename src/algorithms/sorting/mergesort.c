#include "algorithms/sorting/mergesort.h"

#include <stdio.h>
#include "helper/array.h"

// first sub-array is array[left_index...middle_index]
// second sub-array is array[middle_index+1...right_index]
static void merge(int array[], size_t left_index, size_t middle_index, size_t right_index)
{
    const size_t first_array_size = middle_index-left_index+1;
    const size_t second_array_size = right_index-middle_index;

    int first_array[first_array_size];
    int second_array[second_array_size];

    // copy
    printf("\narray: ");
    size_t first_index = 0;
    helper_print_array(array, left_index, right_index);
    for (size_t i=left_index; i<=middle_index; ++i)
    {
        first_array[first_index] = array[i];
        ++first_index;
    }
    size_t second_index = 0;
    for (size_t i=middle_index+1; i<=right_index; ++i)
    {
        second_array[second_index] = array[i];
        ++second_index;
    }

    printf("first array: ");
    helper_print_array(first_array, 0, first_array_size-1);
    printf("second array: ");
    helper_print_array(second_array, 0, second_array_size-1);

    // TODO: clear
    int sorted[left_index + right_index + 1];

    size_t sorted_index = 0;
    first_index = 0;
    second_index = 0;

    while (first_index < first_array_size && second_index < second_array_size)
    {
        if (first_array[first_index] <= second_array[second_index])
        {
            sorted[sorted_index] = first_array[first_index];
            ++sorted_index;
            ++first_index;
        }
        else
        {
            sorted[sorted_index] = second_array[second_index];
            ++sorted_index;
            ++second_index;
        }
    }

    while (first_index < first_array_size)
    {
        sorted[sorted_index] = first_array[first_index];
        ++first_index;
        ++sorted_index;
    }

    while (second_index < second_array_size)
    {
        sorted[sorted_index] = second_array[second_index];
        ++second_index;
        ++sorted_index;
    }

    printf("sorted: ");
    helper_print_array(sorted, 0, sorted_index-1);

    sorted_index = 0;
    for (size_t i=left_index; i<=right_index; ++i)
    {
        array[i] = sorted[sorted_index];
        ++sorted_index;
    }

    printf("array: ");
    helper_print_array(array, left_index, right_index);
}

static void mergesort(int array[], size_t left_index, size_t right_index, size_t size)
{
    if (right_index > 0 && right_index < size && left_index != right_index)
    {
        const size_t middle_index = (left_index + right_index) / 2;

        mergesort(array, left_index, middle_index, size);
        mergesort(array, middle_index + 1, right_index, size);

        merge(array, left_index, middle_index, right_index);
    }
}

error_code sorting_mergesort(int array[], size_t size)
{
    mergesort(array, 0, size-1, size);

    return E_SUCCESS;
}
