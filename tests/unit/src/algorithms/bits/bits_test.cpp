#include <gtest/gtest.h>

extern "C"
{
#include <algorithms/error_code.h>
#include <algorithms/bits/bits.h>
}

namespace
{
TEST(bits_get_number_of_one_bits, basic)
{
    unsigned char ones = 0;

    {
        bits_find_number_of_one_bits(255, &ones);
        EXPECT_EQ(ones, 8);
    }

    {
        bits_find_number_of_one_bits(8, &ones);
        EXPECT_EQ(ones, 1);
    }

    {
        bits_find_number_of_one_bits(2, &ones);
        EXPECT_EQ(ones, 1);
    }

    {
        bits_find_number_of_one_bits(512, &ones);
        EXPECT_EQ(ones, 1);
    }
}
}
