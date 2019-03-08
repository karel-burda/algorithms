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
        vool is_prime = false;

        EXPECT_EQ(number_is_prime(2, &is_prime), E_SUCCESS);
        EXPECT_EQ(is_prime, false);
    }

    {
        vool is_prime = false;

        EXPECT_EQ(number_is_prime(3, &is_prime), E_SUCCESS);
        EXPECT_EQ(is_prime, true);
    }

    {
        vool is_prime = false;

        EXPECT_EQ(number_is_prime(4096, &is_prime), E_SUCCESS);
        EXPECT_EQ(is_prime, false);
    }

    {
        vool is_prime = false;

        EXPECT_EQ(number_is_prime(119, &is_prime), E_SUCCESS);
        EXPECT_EQ(is_prime, true);
    }
}

TEST(prime_test, invalid)
{
    bool is_prime = false;
    EXPECT_EQ(number_prime(0, &is_prime), E_INVALID_INPUT);
    EXPECT_EQ(number_prime(1, &is_prime), E_INVALID_INPUT);
    EXPECT_EQ(number_prime(13, NULL), E_INVALID_INPUT);
}
}
