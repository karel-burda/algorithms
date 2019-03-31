#include <gtest/gtest.h>
#include <test_utils/array.hpp>

extern "C"
{
#include <algorithms/sorting/mergesort.h>
}

namespace
{
TEST(mergesort, basic)
{
    {
        const size_t size = 1;
        int input[size] = {-99};
        int sorted[size] = {-99};

        EXPECT_EQ(sorting_mergesort(input, size), E_SUCCESS);
        BURDA_TEST_UTILS_ARRAY_EXPECT_EQUAL(input, sorted, size);
    }

    {
        const size_t size = 2;
        int input[size] = {-99, 256};
        int sorted[size] = {-99, 256};

        EXPECT_EQ(sorting_mergesort(input, size), E_SUCCESS);
        BURDA_TEST_UTILS_ARRAY_EXPECT_EQUAL(input, sorted, size);
    }

    {
        const size_t size = 3;
        int input[size] = {98, 1, 45};
        int sorted[size] = {1, 45, 98};

        EXPECT_EQ(sorting_mergesort(input, size), E_SUCCESS);
        BURDA_TEST_UTILS_ARRAY_EXPECT_EQUAL(input, sorted, size);
    }

    {
        const size_t size = 7;
        int input[size] = {38, 27, 43, 3, 9, 82, 10};
        int sorted[size] = {3, 9, 10, 27, 38, 43, 82};

        EXPECT_EQ(sorting_mergesort(input, size), E_SUCCESS);
        BURDA_TEST_UTILS_ARRAY_EXPECT_EQUAL(input, sorted, size);
    }
}

TEST(mergesort, invalid)
{
    {
        EXPECT_EQ(sorting_mergesort(NULL, 10), E_INVALID_INPUT);
    }

    {
        const size_t size = 2;
        int input[size] = { 8, 7 };

        EXPECT_EQ(sorting_mergesort(input, 0), E_INVALID_INPUT);
    }
}
}
