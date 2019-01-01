#include <gtest/gtest.h>

extern "C"
{
#include <algorithms/string/strlen.h>
}

namespace
{
TEST(binary_search_test, basic)
{
    {
        EXPECT_EQ(string_strlen("abcdefgh"), 8);
        EXPECT_EQ(string_strlen("ab"), 2);
        EXPECT_EQ(string_strlen(""), 0);
    }
}

TEST(binary_search_test, invalid)
{
    {
        EXPECT_EQ(string_strlen(NULL), 0);
    }
}
}
