#include <math.h>

#include "algorithms/sorting/radix.h"

#include "helper/array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned char get_digit(int number, unsigned char position)
{
    const int number_rounded_to_units = (abs(number) / pow(10, position));
    return (unsigned char)(number_rounded_to_units % 10);
}

static unsigned char get_digits_of_highest_number(int array[], size_t size)
{
    int max = array[0];
    for (size_t i = 1; i < size; ++i)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    unsigned char digits = 0;
    while (max != 0)
    {
        max /= 10;
        ++digits;
    }

    return digits;
}

static void sort_according_to_digits(int array[], size_t size)
{
    // in decimal, we have 9 digits: 0-9
    const unsigned char digits = 10;
    const size_t bucket_size = size;

    // we could do that in the first pass, but the code would be less read-able
    const unsigned char number_of_digits = get_digits_of_highest_number(array, size);

    for (unsigned char digit_index = 0; digit_index < number_of_digits; ++digit_index)
    {
        printf("digit: %d\n", digit_index);
        helper_print_array(array, 0, size-1);

        // cannot initialize variable-sized objects
        size_t buckets[digits][bucket_size];
        memset(&buckets, 0, sizeof(bucket_size));
        size_t bucket_sizes[digits] = {0};

        for (size_t i = 0; i < size; ++i)
        {
            const int current_number = array[i];
            const int current_digit = get_digit(current_number, digit_index);

            const size_t current_bucket_size = bucket_sizes[current_digit];
            buckets[current_digit][current_bucket_size] = current_number;
            ++bucket_sizes[current_digit];
        }

        size_t current_index = 0;
        for (unsigned char i = 0; i < digits; ++i)
        {
            for (unsigned char j = 0; j < bucket_sizes[i]; ++j)
            {
                array[current_index++] = buckets[i][j];
            }
        }

        helper_print_array(array, 0, size-1);
    }
}

static void sort_according_to_sign(int array[], size_t size)
{


    // TODO: remove
    size_t number_of_negatives = 0;
    for (size_t i = 0; i< size; ++i)
    {
        if (array[i] < 0)
        {
            ++number_of_negatives;
        }
    }

    if (number_of_negatives > 0) {
        int negatives[number_of_negatives];
        int positives_or_zero[size - number_of_negatives];
        memset(&negatives, 0, sizeof(negatives));
        memset(&positives_or_zero, 0, sizeof(positives_or_zero));
        size_t negatives_index = 0;
        size_t positives_or_zero_index = 0;

        for (size_t i = 0; i < size; ++i) {
            const int current_number = array[i];

            if (current_number >= 0) {
                positives_or_zero[positives_or_zero_index] = current_number;
                ++positives_or_zero_index;
            } else {
                negatives[negatives_index] = current_number;
                ++negatives_index;
            }
        }

        size_t array_index = 0;
        for (size_t i = negatives_index; i > 0; --i) {
            array[array_index] = negatives[i - 1];
            ++array_index;
        }
        for (size_t i = 0; i < positives_or_zero_index; ++i) {
            array[array_index] = positives_or_zero[i];
            ++array_index;
        }
    }
}

static void radix(int array[], size_t size)
{
    sort_according_to_digits(array, size);
    sort_according_to_sign(array, size);
}

error_code sorting_radix(int array[], size_t size)
{
    if (array == NULL || size == 0)
    {
        return E_INVALID_INPUT;
    }

    radix(array, size);

    return E_SUCCESS;
}
