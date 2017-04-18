#ifdef TEST_BUILD

#include "Catch.h"
#include "streams/converters/conversions.h"
#include "tests/testlib.h"


TEST_CASE("convert_uint8_to_double_stream {}")
{
    auto uint8_stream = STREAM(uint8_t);
    auto double_stream = convert_uint8_to_double_stream(uint8_stream);

    REQUIRE(double_stream->size() == 0);
}

TEST_CASE("convert_uint8_to_double_stream {0}")
{
    auto uint8_stream = STREAM(uint8_t, 0);
    auto double_stream = convert_uint8_to_double_stream(uint8_stream);

    REQUIRE(double_stream->size() == 1);
    REQUIRE((*double_stream)[0] == -1);
}

TEST_CASE("convert_uint8_to_double_stream {255}")
{
    auto uint8_stream = STREAM(uint8_t, 255);
    auto double_stream = convert_uint8_to_double_stream(uint8_stream);

    REQUIRE(double_stream->size() == 1);
    REQUIRE((*double_stream)[0] == 1);
}

TEST_CASE("convert_uint8_to_double_stream {255, 0, 0, 255}")
{
    auto uint8_stream = STREAM(uint8_t, 255, 0, 0, 255);
    auto double_stream = convert_uint8_to_double_stream(uint8_stream);

    REQUIRE(double_stream->size() == 4);
    REQUIRE((*double_stream)[0] == 1);
    REQUIRE((*double_stream)[1] == -1);
    REQUIRE((*double_stream)[2] == -1);
    REQUIRE((*double_stream)[3] == 1);
}

#endif
