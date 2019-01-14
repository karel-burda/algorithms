#include <gtest/gtest.h>

extern "C"
{
#include <algorithms/error_code.h>
#include <algorithms/string/unique.h>
}

namespace
{
TEST(string_unique, basic)
{
    bool has_only_unique_characters = false;

    {
        ASSERT_EQ(string_has_unique_characters_ascii("aaa", &has_only_unique_characters), E_SUCCESS);
        EXPECT_FALSE(has_only_unique_characters);
    }

    {
        ASSERT_EQ(string_has_unique_characters_ascii("abced987", &has_only_unique_characters), E_SUCCESS);
        EXPECT_TRUE(has_only_unique_characters);
    }

    {
        ASSERT_EQ(string_has_unique_characters_ascii("f8907-x/f", &has_only_unique_characters), E_SUCCESS);
        EXPECT_FALSE(has_only_unique_characters);
    }
}

TEST(string_unique, invalid)
{
    bool has_only_unique_characters = false;
    EXPECT_EQ(string_has_unique_characters_ascii(NULL, &has_only_unique_characters), E_INVALID_INPUT);
    EXPECT_EQ(string_has_unique_characters_ascii("boo", NULL), E_INVALID_INPUT);
    EXPECT_EQ(string_has_unique_characters_ascii(NULL, NULL), E_INVALID_INPUT);
}
}
