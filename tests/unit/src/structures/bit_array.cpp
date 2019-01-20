#include <cstring>
#include <memory>

#include <gtest/gtest.h>

extern "C"
{
#include <algorithms/error_code.h>
#include <structures/bit_array.h>
}

namespace
{
class structures_bit_array_fixture : public ::testing::Test
{
    protected:
        void SetUp() override
        {
            // construct structure manually with help of RAII wrappers
            bit_array = std::make_unique<structures_bit_array>();
            array = std::make_unique<unsigned char []>(2);
            bit_array->array = array.get();

            // fill test values
            bit_array->array[0] = 9;
            bit_array->array[1] = 128;
            bit_array->size = 11;

            // array now should look like this in terms of bits:
            // |0|0|0|0|1|0|0|1| |1|0|0|0|0|0|0|0|
        }

        void TearDown() override
        {
        }

        std::unique_ptr<structures_bit_array> bit_array;
        std::unique_ptr<unsigned char []> array;
};

TEST(structures_bit_array, lifetime)
{
    structures_bit_array * bit_array = NULL;

    {
        ASSERT_EQ(structures_bit_array_create(&bit_array, 10), E_SUCCESS);
        ASSERT_TRUE(bit_array);
        EXPECT_TRUE(bit_array->array);
        EXPECT_EQ(bit_array->size, 2);

        // it should look like plain array of 2 bytes (filled with zeros)
        unsigned char blueprint[] = { 0, 0 };
        std::memcmp(bit_array->array, blueprint, 2);

        ASSERT_EQ(structures_bit_array_destroy(&bit_array), E_SUCCESS);
        ASSERT_FALSE(bit_array);
    }

    {
        ASSERT_EQ(structures_bit_array_create(&bit_array, 24), E_SUCCESS);
        ASSERT_TRUE(bit_array);
        EXPECT_TRUE(bit_array->array);
        EXPECT_EQ(bit_array->size, 3);

        unsigned char blueprint[] = { 0, 0, 0 };
        std::memcmp(bit_array->array, blueprint, 3);

        ASSERT_EQ(structures_bit_array_destroy(&bit_array), E_SUCCESS);
        ASSERT_FALSE(bit_array);
    }
}

TEST(structures_bit_array, invalid)
{
    ASSERT_EQ(structures_bit_array_destroy(NULL), E_INVALID_INPUT);
}

TEST_F(structures_bit_array_fixture, get)
{
    unsigned char bit = 0;

    EXPECT_EQ(structures_bit_array_get(bit_array.get(), 0, &bit), E_SUCCESS);
    EXPECT_EQ(bit, 0);

    EXPECT_EQ(structures_bit_array_get(bit_array.get(), 4, &bit), E_SUCCESS);
    EXPECT_EQ(bit, 1);

    EXPECT_EQ(structures_bit_array_get(bit_array.get(), 8, &bit), E_SUCCESS);
    EXPECT_EQ(bit, 1);
}

TEST_F(structures_bit_array_fixture, set)
{
    // same value twice
    {
        EXPECT_EQ(structures_bit_array_set(bit_array.get(), 0, 1), E_SUCCESS);
        EXPECT_EQ(array[0], 137);

        EXPECT_EQ(structures_bit_array_set(bit_array.get(), 0, 1), E_SUCCESS);
        EXPECT_EQ(array[0], 137);
    }

    {
        EXPECT_EQ(structures_bit_array_set(bit_array.get(), 7, 1), E_SUCCESS);
        EXPECT_EQ(array[0], 137);
    }

    EXPECT_EQ(structures_bit_array_set(bit_array.get(), 0, 0), E_SUCCESS);
    EXPECT_EQ(array[0], 9);
}

TEST(structures_bit_array, full)
{
    structures_bit_array * bit_array = NULL;

    ASSERT_EQ(structures_bit_array_create(&bit_array, 10), E_SUCCESS);

    unsigned char bit = 0;

    EXPECT_EQ(structures_bit_array_get(bit_array, 4, &bit), E_SUCCESS);
    EXPECT_EQ(bit, 0);
    EXPECT_EQ(structures_bit_array_set(bit_array, 4, 1), E_SUCCESS);
    EXPECT_EQ(structures_bit_array_get(bit_array, 4, &bit), E_SUCCESS);
    EXPECT_EQ(bit, 1);

    EXPECT_EQ(structures_bit_array_get(bit_array, 9, &bit), E_SUCCESS);
    EXPECT_EQ(bit, 0);
    EXPECT_EQ(structures_bit_array_set(bit_array, 9, 1), E_SUCCESS);
    EXPECT_EQ(structures_bit_array_get(bit_array, 9, &bit), E_SUCCESS);
    EXPECT_EQ(bit, 1);

    ASSERT_EQ(structures_bit_array_destroy(&bit_array), E_SUCCESS);
}
}
