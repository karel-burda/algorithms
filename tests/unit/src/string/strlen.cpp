#include <gtest/gtest.h>

extern "C"
{
#include <algorithms/string/strlen.h>
}

namespace
{
TEST(string_strlen, basic)
{
    EXPECT_EQ(string_strlen("abcdefgh"), 8);
    EXPECT_EQ(string_strlen("ab"), 2);
    EXPECT_EQ(string_strlen(""), 0);
}

TEST(string_strlen, invalid)
{
    EXPECT_EQ(string_strlen(NULL), 0);
}
}
