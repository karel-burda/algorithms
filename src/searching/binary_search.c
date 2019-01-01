#include <stdbool.h>

#include "algorithms/searching/binary_search.h"

static size_t get_middle_index(size_t left_index, size_t right_index)
{
    return (left_index + right_index) / 2;
}

static int binary_search_recursive(int array[], size_t size, size_t left_index, size_t right_index, int element)
{
    if (left_index == right_index || right_index > size - 1)
    {
        return -1;
    }

    const size_t middle_index = get_middle_index(left_index, right_index);
    const int middle_element = array[middle_index];

    if (middle_element == element)
    {
        return middle_index;
    }
    else if (middle_element > element)
    {
        return binary_search_recursive(array, size, left_index, middle_index - 1, element);
    }
    else
    {
        return binary_search_recursive(array, size, middle_index + 1, right_index, element);
    }
}

static int binary_search_iterative(int array[], size_t size, size_t left_index, size_t right_index, int element) {
    // TODO: optimize
    while (true)
    {
        if (left_index == right_index || right_index > size - 1)
        {
            return -1;
        }

        const size_t middle_index = get_middle_index(left_index, right_index);
        const int middle_element = array[middle_index];

        if (middle_element == element)
        {
            return middle_index;
        }
        else if (middle_element > element)
        {
            right_index = middle_index - 1;
        }
        else
        {
            left_index = middle_element + 1;
        }
    }
}

int searching_binary_search_recursive(int array[], size_t size, int element)
{
    if (array != NULL && size != 0)
    {
        return binary_search_recursive(array, size, 0, size-1, element);
    }
    else
    {
        return -1;
    }
}

int searching_binary_search_iterative(int array[], size_t size, int element)
{
    if (array != NULL && size != 0)
    {
        return binary_search_iterative(array, size, 0, size-1, element);
    }
    else
    {
        return -1;
    }
}
