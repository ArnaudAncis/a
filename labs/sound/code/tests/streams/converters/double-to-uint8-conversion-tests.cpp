#ifdef TEST_BUILD

#include "Catch.h"
#include "streams/converters/conversions.h"
#include "tests/testlib.h"


TEST_CASE("convert_double_to_uint8_stream {}")
{
    auto double_stream = STREAM(double);
    auto uint8_stream = convert_double_to_uint8_stream(double_stream);

    REQUIRE(uint8_stream->size() == 0);
}

TEST_CASE("convert_double_to_uint8_stream {-1}")
{
    auto double_stream = STREAM(double, -1);
    auto uint8_stream = convert_double_to_uint8_stream(double_stream);

    REQUIRE(uint8_stream->size() == 1);
    REQUIRE((*uint8_stream)[0] == 0);
}

TEST_CASE("convert_double_to_uint8_stream {1}")
{
    auto double_stream = STREAM(double, 1);
    auto uint8_stream = convert_double_to_uint8_stream(double_stream);

    REQUIRE(uint8_stream->size() == 1);
    REQUIRE((*uint8_stream)[0] == 255);
}

#endif
