#include <thread>

#include <gtest/gtest.h>

extern "C"
{
#include <algorithms/searching/binary_search.h>
}

namespace
{
TEST(binary_search_test_recursive, basic)
{
    {
        int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        EXPECT_EQ(searching_binary_search_recursive(array, 10, 5), 4);
    }

    {
        int array[] = { 1, 1, 1, 1, 1 };
        EXPECT_EQ(searching_binary_search_recursive(array, 5, 1), 2);
    }
}

TEST(binary_search_test_recursive, invalid)
{
    {
        int array[] = { 0 };
        EXPECT_EQ(searching_binary_search_recursive(array, 0, 0), -1);
    }

    {
        EXPECT_EQ(searching_binary_search_recursive(NULL, 0, 0), -1);
    }
}
}
