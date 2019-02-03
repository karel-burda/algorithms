#include <gtest/gtest.h>

extern "C"
{
#include <algorithms/bytes/endianness.h>
}

namespace
{
TEST(bytes_get_endianness, basic)
{
    endianness result = E_UNKNOWN;
    EXPECT_EQ(bytes_get_endianness(&result), E_SUCCESS);

#if defined(__x86_64__) || defined(_M_X64) || defined(__i386) || defined(_M_IX86)
    EXPECT_EQ(result, E_LITTLE_ENDIAN);
#else
    EXPECT_EQ(result, E_BIG_ENDIAN);
#endif
}
}
