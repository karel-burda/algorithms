#include <gtest/gtest.h>

extern "C"
{
#include <algorithms/number/prime.h>
}

namespace
{
TEST(prime_test, basic)
{
    {
        bool is_prime = false;

        EXPECT_EQ(number_is_prime_using_division(2, &is_prime), E_SUCCESS);
        EXPECT_EQ(is_prime, false);
    }

    {
        bool is_prime = false;

        EXPECT_EQ(number_is_prime_using_division(3, &is_prime), E_SUCCESS);
        EXPECT_EQ(is_prime, true);
    }

    {
        bool is_prime = false;

        EXPECT_EQ(number_is_prime_using_division(11, &is_prime), E_SUCCESS);
        EXPECT_EQ(is_prime, true);
    }

    {
        bool is_prime = false;

        EXPECT_EQ(number_is_prime_using_division(4096, &is_prime), E_SUCCESS);
        EXPECT_EQ(is_prime, false);
    }

    {
        bool is_prime = false;

        EXPECT_EQ(number_is_prime_using_division(119, &is_prime), E_SUCCESS);
        EXPECT_EQ(is_prime, false);
    }

    {
        bool is_prime = false;

        EXPECT_EQ(number_is_prime_using_division(4297, &is_prime), E_SUCCESS);
        EXPECT_EQ(is_prime, true);
    }
}

TEST(prime_test, invalid)
{
    bool is_prime = false;
    EXPECT_EQ(number_is_prime_using_division(0, &is_prime), E_INVALID_INPUT);
    EXPECT_EQ(number_is_prime_using_division(1, &is_prime), E_INVALID_INPUT);
    EXPECT_EQ(number_is_prime_using_division(13, NULL), E_INVALID_INPUT);
}
}
