#include <thread>

#include <gtest/gtest.h>

// TODO: move extern to the algorithms
extern "C"
{
#include <algorithms/number/swap.h>
}

namespace
{
TEST(swap_test, basic)
{
    {
        int number1 = 1;
        int number2 = 99;

        EXPECT_EQ(number_swap(&number1, &number2), 0);
        EXPECT_EQ(number1, 99);
        EXPECT_EQ(number2, 1);
    }

    {
        int number1 = 1024;
        int number2 = -4096;

        EXPECT_EQ(number_swap(&number1, &number2), 0);
        EXPECT_EQ(number1, -4096);
        EXPECT_EQ(number2, 1024);
    }

    {
        int number1 = -522;
        int number2 = number1;

        EXPECT_EQ(number_swap(&number1, &number2), 0);
        EXPECT_EQ(number1, -522);
        EXPECT_EQ(number2, -522);
    }
}

TEST(swap_test, invalid)
{
    int number = 0;
    EXPECT_EQ(number_swap(NULL, &number), -1);
    EXPECT_EQ(number_swap(&number, NULL), -1);
    EXPECT_EQ(number_swap(NULL, NULL), -1);
}
}
