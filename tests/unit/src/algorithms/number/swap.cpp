#include <gtest/gtest.h>

extern "C"
{
#include <algorithms/error_code.h>
#include <algorithms/number/swap.h>
}

namespace
{
TEST(swap_test, basic)
{
    {
        int number1 = 1;
        int number2 = 99;

        EXPECT_EQ(number_swap(&number1, &number2), E_SUCCESS);
        EXPECT_EQ(number1, 99);
        EXPECT_EQ(number2, 1);
    }

    {
        int number1 = 1024;
        int number2 = -4096;

        EXPECT_EQ(number_swap(&number1, &number2), E_SUCCESS);
        EXPECT_EQ(number1, -4096);
        EXPECT_EQ(number2, 1024);
    }

    {
        int number1 = -522;
        int number2 = number1;

        EXPECT_EQ(number_swap(&number1, &number2), E_SUCCESS);
        EXPECT_EQ(number1, -522);
        EXPECT_EQ(number2, -522);
    }
}

TEST(swap_test, invalid)
{
    int number = 0;
    EXPECT_EQ(number_swap(NULL, &number), E_INVALID_INPUT);
    EXPECT_EQ(number_swap(&number, NULL), E_INVALID_INPUT);
    EXPECT_EQ(number_swap(NULL, NULL), E_INVALID_INPUT);
}
}
