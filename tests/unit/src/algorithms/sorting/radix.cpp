#include <gtest/gtest.h>
#include <test_utils/array.hpp>

extern "C"
{
#include <algorithms/sorting/radix.h>
}

namespace
{
TEST(radix, basic)
{
    {
        const size_t size = 5;
        int input[size] = {7, 3, 256, 1048, 10};
        int sorted[size] = {3, 7, 10, 256, 1048};

        EXPECT_EQ(sorting_radix(input, size), E_SUCCESS);
        BURDA_TEST_UTILS_ARRAY_EXPECT_EQUAL(input, sorted, size);
    }

    {
        const size_t size = 6;
        int input[size] = {7, 3, -256, 1048, -10, 0};
        int sorted[size] = {-256, -10, 0, 3, 7, 1048};

        EXPECT_EQ(sorting_radix(input, size), E_SUCCESS);
        BURDA_TEST_UTILS_ARRAY_EXPECT_EQUAL(input, sorted, size);
    }

    {
        const size_t size = 8;
        int input[size] = {170, 45, 75, 90, 2, 802, 2, 66};
        int sorted[size] = {2, 2, 45, 66, 75, 90, 170, 802};

        EXPECT_EQ(sorting_radix(input, size), E_SUCCESS);
        BURDA_TEST_UTILS_ARRAY_EXPECT_EQUAL(input, sorted, size);
    }
}

TEST(radix, invalid)
{
    EXPECT_EQ(sorting_radix(NULL, 9), E_INVALID_INPUT);
    int input[] = {1, 2};
    EXPECT_EQ(sorting_radix(input, 0), E_INVALID_INPUT);
}
}
