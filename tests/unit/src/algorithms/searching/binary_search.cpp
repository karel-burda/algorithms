#include <gtest/gtest.h>

extern "C"
{
#include <algorithms/error_code.h>
#include <algorithms/searching/binary_search.h>
}

namespace
{
TEST(binary_search_test, basic)
{
    {
        int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        EXPECT_EQ(searching_binary_search_recursive(array, 10, 5), 4);
        EXPECT_EQ(searching_binary_search_iterative(array, 10, 5), 4);

        EXPECT_EQ(searching_binary_search_recursive(array, 10, 999), E_NOT_FOUND);
        EXPECT_EQ(searching_binary_search_iterative(array, 10, 999), E_NOT_FOUND);

        EXPECT_EQ(searching_binary_search_recursive(array, 10, 0), E_NOT_FOUND);
        EXPECT_EQ(searching_binary_search_iterative(array, 10, 0), E_NOT_FOUND);
    }

    {
        int array[] = { 1, 1, 1, 1, 1 };

        EXPECT_EQ(searching_binary_search_recursive(array, 5, 1), 2);
        EXPECT_EQ(searching_binary_search_iterative(array, 5, 1), 2);
    }
}

TEST(binary_search_test, invalid)
{
    {
        int array[] = { 0 };

        EXPECT_EQ(searching_binary_search_recursive(array, 0, 0), E_INVALID_INPUT);
        EXPECT_EQ(searching_binary_search_iterative(array, 0, 0), E_INVALID_INPUT);
    }

    {
        EXPECT_EQ(searching_binary_search_recursive(NULL, 0, 0), E_INVALID_INPUT);
        EXPECT_EQ(searching_binary_search_iterative(NULL, 0, 0), E_INVALID_INPUT);
    }
}
}
