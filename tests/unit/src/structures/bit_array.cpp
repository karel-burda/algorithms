#include <memory>

#include <gtest/gtest.h>

extern "C"
{
#include <algorithms/error_code.h>
#include <structures/bit_array.h>
}

namespace
{
class structures_bit_array_fixture : public ::testing::Test {
    protected:
        void SetUp() override
        {
            // construct structure manually with help of RAII wrappers
            bit_array = std::make_unique<::bit_array>();
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

        std::unique_ptr<::bit_array> bit_array;
        std::unique_ptr<unsigned char []> array;
};

TEST(structures_bit_array, lifetime)
{
    bit_array * array = NULL;

    {
        ASSERT_EQ(structures_bit_array_create(&array, 9), E_SUCCESS);
        ASSERT_TRUE(array);
        EXPECT_TRUE(array->array);
        EXPECT_EQ(array->size, 2);

        // it should look like plain array of 2 bytes (filled with zeros)
        unsigned char blueprint[] = { 0, 0 };
        std::memcmp(array->array, blueprint, 2);
    }

    {
        ASSERT_EQ(structures_bit_array_destroy(&array), E_SUCCESS);
        ASSERT_FALSE(array);
    }
}

TEST(structures_bit_array, invalid)
{
    ASSERT_EQ(structures_bit_array_destroy(NULL), E_INVALID_INPUT);
}

TEST_F(structures_bit_array_fixture, get)
{
    unsigned char result = 0;

    EXPECT_EQ(structures_bit_array_get(bit_array.get(), 0, &result), E_SUCCESS);
    EXPECT_EQ(result, 0);

    EXPECT_EQ(structures_bit_array_get(bit_array.get(), 4, &result), E_SUCCESS);
    EXPECT_EQ(result, 1);

    EXPECT_EQ(structures_bit_array_get(bit_array.get(), 8, &result), E_SUCCESS);
    EXPECT_EQ(result, 1);
}
}
