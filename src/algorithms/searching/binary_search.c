#include <stdbool.h>

#include "algorithms/error_code.h"
#include "algorithms/searching/binary_search.h"

static size_t get_middle_index(size_t left_index, size_t right_index)
{
    return (left_index + right_index) / 2;
}

static int binary_search_recursive(const int array[], size_t size, size_t left_index, size_t right_index, int element)
{
    // TODO: watch for underflow (size_t)
    if (left_index == right_index || right_index > size - 1)
    {
        return E_NOT_FOUND;
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

static error_code binary_search_iterative(const int array[], size_t size, size_t left_index, size_t right_index, int element)
{
    while (true)
    {
        if (left_index == right_index || right_index > size - 1)
        {
            return E_NOT_FOUND;
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
            left_index = middle_index + 1;
        }
    }
}

static error_code binary_search(int(* search_function)(const int[], size_t, size_t, size_t, int), const int array[], size_t size, int element)
{
    if (array != NULL && size != 0)
    {
        return search_function(array, size, 0, size - 1, element);
    }
    else
    {
        return E_INVALID_INPUT;
    }
}

error_code searching_binary_search_recursive(const int array[], size_t size, int element)
{
    return binary_search(binary_search_recursive, array, size, element);
}

error_code searching_binary_search_iterative(const int array[], size_t size, int element)
{
    return binary_search(binary_search_iterative, array, size, element);
}
