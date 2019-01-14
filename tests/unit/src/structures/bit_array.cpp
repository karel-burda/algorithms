#include <gtest/gtest.h>

extern "C"
{
#include <algorithms/error_code.h>
#include <structures/bit_array.h>
}

namespace
{
TEST(bit_array_test, lifetime)
{
    bit_array * array = NULL;
    ASSERT_EQ(structures_bit_array_create(&array, 9), E_SUCCESS);
    ASSERT_TRUE(array);
    EXPECT_TRUE(array->array);
    EXPECT_EQ(array->size, 2);

    ASSERT_EQ(structures_bit_array_destroy(array), E_SUCCESS);
    ASSERT_FALSE(array);
}
}
