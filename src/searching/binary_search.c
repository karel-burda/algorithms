#include "algorithms/searching/binary_search.h"

static int binary_search(int array[], size_t left_index, size_t right_index, int element)
{
    const size_t middle_index = array[left_index + right_index]/2;
    const int middle_element = array[middle_index];

    if (middle_element == element)
    {
        return middle_index;
    }
    else if (middle_element > element)
    {
        return binary_search(array, left_index, middle_index-1, element);
    }
    else
    {
        return binary_search(array, middle_index+1, right_index, element);
    }

}

int searching_binary_search(int array[], size_t size, int element)
{
    if (array != NULL)
    {
        return binary_search(array, 0, size-1, element);
    }
    else
    {
        return -1;
    }
}
