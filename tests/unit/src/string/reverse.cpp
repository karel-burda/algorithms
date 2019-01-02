#include <gtest/gtest.h>

extern "C"
{
#include <algorithms/error_code.h>
#include <algorithms/string/reverse.h>
}

namespace
{
TEST(string_reverse_test, basic)
{
    {
        char string[] = "A";
        const int result = string_reverse(string);
        ASSERT_EQ(result, E_SUCCESS);
        EXPECT_STREQ(string, "A");
    }

    {
        char string[] = "12345";
        const int result = string_reverse(string);
        ASSERT_EQ(result, E_SUCCESS);
        EXPECT_STREQ(string, "54321");
    }
}

TEST(string_reverse_test, invalid)
{
    {
        EXPECT_EQ(string_reverse(NULL), E_INVALID_INPUT);
    }

    {
        char string[] = "";
        const int result = string_reverse(string);
        EXPECT_EQ(result, E_INVALID_INPUT);
        EXPECT_STREQ(string, "");
    }
}
}
