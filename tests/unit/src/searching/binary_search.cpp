#include <thread>

#include <gtest/gtest.h>

extern "C"
{
#include <algorithms/searching/binary_search.h>
}

namespace
{
    TEST(binary_search_test, basic)
    {
        int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        EXPECT_EQ(searching_binary_search(array, 10, 5), 4);
    }
}
