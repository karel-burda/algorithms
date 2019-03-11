#include <gtest/gtest.h>

extern "C"
{
#include <algorithms/string/permutation.h>
}

namespace
{
class strings_permutation_fixture : public ::testing::Test
{
    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
            delete[] permutations;
            permutations = nullptr;
        }

        char ** permutations = nullptr;
};

TEST_F(strings_permutation_fixture, basic)
{
    {
        char string[] = "ABC";
        size_t number_of_permutations = 0;

        EXPECT_EQ(string_get_all_permutations(string, strlen(string), &permutations, &number_of_permutations), E_SUCCESS);
        ASSERT_NE(permutations, nullptr);
        EXPECT_EQ(number_of_permutations, 6);
        EXPECT_STREQ(permutations[0], "ABC");
        EXPECT_STREQ(permutations[1], "ACB");
        EXPECT_STREQ(permutations[2], "BAC");
        EXPECT_STREQ(permutations[3], "BCA");
        EXPECT_STREQ(permutations[4], "CBA");
        EXPECT_STREQ(permutations[5], "CAB");
    }
}
}
