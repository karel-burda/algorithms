#include <gtest/gtest.h>
#include <test_utils/array.hpp>

extern "C"
{
#include <algorithms/error_code.h>
#include <algorithms/sorting/quicksort.h>
}

namespace
{
TEST(quicksort, odd_size)
{
    {
        const size_t size = 1;
        int input[size] = { -6500 };
        int sorted[size] = { -6500 };

        EXPECT_EQ(sorting_quicksort_recursive(input, size), E_SUCCESS);
        BURDA_TEST_UTILS_ARRAY_EXPECT_EQUAL(input, sorted, size)
    }

    {
        const size_t size = 3;
        int input[size] = { 1, 3, 2 };
        int sorted[size] = { 1, 2, 3 };

        EXPECT_EQ(sorting_quicksort_recursive(input, size), E_SUCCESS);
        BURDA_TEST_UTILS_ARRAY_EXPECT_EQUAL(input, sorted, size);
    }

    {
        const size_t size = 9;
        int input[size] = { 1, 3, 1, 877, -56, 8, 1, 11, 11 };
        int sorted[size] = { -56, 1, 1, 1, 3, 8, 11, 11, 877 };

        EXPECT_EQ(sorting_quicksort_recursive(input, size), E_SUCCESS);
        BURDA_TEST_UTILS_ARRAY_EXPECT_EQUAL(input, sorted, size);
    }

    {
        const size_t size = 3;
        int input[size] = { 1, 3, 1 };
        int sorted[size] = { 1, 1, 3 };

        EXPECT_EQ(sorting_quicksort_recursive(input, size), E_SUCCESS);
        BURDA_TEST_UTILS_ARRAY_EXPECT_EQUAL(input, sorted, size);
    }
}

TEST(quicksort_test, even_size)
{
    {
        const size_t size = 2;
        int input[size] = { 2, 1024 };
        int sorted[size] = { 2, 1024 };

        EXPECT_EQ(sorting_quicksort_recursive(input, size), E_SUCCESS);
        BURDA_TEST_UTILS_ARRAY_EXPECT_EQUAL(input, sorted, size);
    }

    {
        const size_t size = 2;
        int input[size] = { 2, -544 };
        int sorted[size] = { -544, 2 };

        EXPECT_EQ(sorting_quicksort_recursive(input, size), E_SUCCESS);
        BURDA_TEST_UTILS_ARRAY_EXPECT_EQUAL(input, sorted, size);
    }

    {
        const size_t size = 8;
        int input[size] = { 8, 7, 6, 5, 900, 900, 2, -65 };
        int sorted[size] = { -65, 2, 5, 6, 7, 8, 900, 900 };

        EXPECT_EQ(sorting_quicksort_recursive(input, size), E_SUCCESS);
        BURDA_TEST_UTILS_ARRAY_EXPECT_EQUAL(input, sorted, size);
    }
}

TEST(quicksort_test, invalid)
{
    {
        EXPECT_EQ(sorting_quicksort_recursive(NULL, 10), E_INVALID_INPUT);
    }

    {
        const size_t size = 2;
        int input[size] = { 8, 7 };

        EXPECT_EQ(sorting_quicksort_recursive(input, 0), E_INVALID_INPUT);
    }
}
}
