#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms/string/permutation.h"

error_code string_are_permutations(const char * first, const char * second, size_t length, bool * permutations)
{
    return E_SUCCESS;
}

static void swap(char string[], const size_t i, const size_t j)
{
    char temp = string[i];
    string[i] = string[j];
    string[j] = temp;
}

static void get_all_permutations(char * string, int fixed_index, int length, char ** permutations, size_t * permutations_size)
{
    if (fixed_index >= length)
    {
        permutations[*permutations_size] = calloc(length, sizeof(char));
        strncpy(permutations[*permutations_size], string, length);
        (*permutations_size)++;
        return;
    }

    for (int i=fixed_index; i<length; ++i)
    {
        swap(string, fixed_index, i);
        get_all_permutations(string, fixed_index + 1, length, permutations, permutations_size);
        swap(string, fixed_index, i);
    }
}

static size_t factorial(size_t number)
{
    return (size_t)tgamma(number + 1);
}

error_code string_get_all_permutations(char * string, size_t length, char *** permutations, size_t * permutations_size)
{
    *permutations = calloc(factorial(length), sizeof(*permutations));
    get_all_permutations(string, 0, strlen(string), *permutations, permutations_size);

    return E_SUCCESS;
}
