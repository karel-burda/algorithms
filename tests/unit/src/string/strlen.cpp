#include <gtest/gtest.h>

extern "C"
{
#include <algorithms/error_code.h>
#include <algorithms/string/strlen.h>
}

namespace
{
TEST(string_strlen, basic)
{
    size_t length = 0;

    {
        ASSERT_EQ(string_strlen("abcdefgh", &length), E_SUCCESS);
        EXPECT_EQ(length, 8);
    }

    {
        ASSERT_EQ(string_strlen("ab", &length), E_SUCCESS);
        EXPECT_EQ(length, 2);
    }

    {
        ASSERT_EQ(string_strlen("", &length), E_SUCCESS);
        EXPECT_EQ(length, 0);
    }
}

TEST(string_strlen, invalid)
{
    size_t length = 0;
    EXPECT_EQ(string_strlen(NULL, &length), E_INVALID_INPUT);
    EXPECT_EQ(string_strlen("foo", NULL), E_INVALID_INPUT);
    EXPECT_EQ(string_strlen(NULL, NULL), E_INVALID_INPUT);
}
}
