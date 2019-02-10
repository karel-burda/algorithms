#include "algorithms/error_code.h"
#include "algorithms/number/swap.h"
#include "algorithms/sorting/quicksort.h"

static size_t get_pivot_index(size_t left_index, size_t right_index)
{
    return (left_index + right_index)/2;
}

static size_t partition(int array[], size_t left_index, size_t right_index)
{
    const int pivot = array[get_pivot_index(left_index, right_index)];
    while (left_index <= right_index)
    {
        while (array[left_index] < pivot)
        {
            ++left_index;
        }

        while (array[right_index] > pivot)
        {
            --right_index;
        }

        if (left_index <= right_index)
        {
            number_swap(&array[left_index], &array[right_index]);
            ++left_index;

            if (right_index > 0)
            {
                --right_index;
            }
        }
    }

    return left_index;
}

static void quicksort_recursive(int array[], size_t left_index, size_t right_index)
{
    const size_t partition_index = partition(array, left_index, right_index);

    if (left_index < partition_index - 1)
    {
        quicksort_recursive(array, left_index, partition_index - 1);
    }

    if (partition_index < right_index) {
        quicksort_recursive(array, partition_index, right_index);
    }
}

error_code sorting_quicksort_recursive(int array[], size_t size)
{
    if (array != NULL && size != 0)
    {
        if (size > 1)
        {
            quicksort_recursive(array, 0, size - 1);
        }

        return E_SUCCESS;
    }
    else
    {
        return E_INVALID_INPUT;
    }
}
