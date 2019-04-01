#include "algorithms/sorting/mergesort.h"

// first sub-array is array[left_index...middle_index]
// second sub-array is array[middle_index+1...right_index]
static void merge(int array[], size_t left_index, size_t middle_index, size_t right_index)
{
    const size_t first_array_size = middle_index-left_index + 1;
    const size_t second_array_size = right_index-middle_index;

    int first_array[first_array_size];
    int second_array[second_array_size];

    size_t first_index = 0;
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

    size_t sorted_index = left_index;
    first_index = 0;
    second_index = 0;
    while (first_index < first_array_size && second_index < second_array_size)
    {
        if (first_array[first_index] <= second_array[second_index])
        {
            array[sorted_index] = first_array[first_index];
            ++first_index;
        }
        else
        {
            array[sorted_index] = second_array[second_index];
            ++second_index;
        }

        ++sorted_index;
    }

    while (first_index < first_array_size)
    {
        array[sorted_index++] = first_array[first_index++];
    }

    // no need to copy the second_array into array, because it's already there & is sorted
}

static size_t get_middle_index_and_avoid_overflow(size_t left_index, size_t right_index)
{
    return left_index/2 + right_index/2;
}

static void mergesort(int array[], size_t left_index, size_t right_index, size_t size)
{
    if (right_index > 0 && right_index < size && left_index != right_index)
    {
        const size_t middle_index = get_middle_index_and_avoid_overflow(left_index, right_index);

        mergesort(array, left_index, middle_index, size);
        mergesort(array, middle_index + 1, right_index, size);

        merge(array, left_index, middle_index, right_index);
    }
}

error_code sorting_mergesort(int array[], size_t size)
{
    if (array != NULL && size > 0)
    {
        mergesort(array, 0, size - 1, size);

        return E_SUCCESS;
    }
    else
    {
        return E_INVALID_INPUT;
    }
}
