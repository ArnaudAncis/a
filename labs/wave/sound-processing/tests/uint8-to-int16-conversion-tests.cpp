#ifdef TEST_BUILD

#include "Catch.h"
#include "streams/conversions.h"
#include "tests/testlib.h"


TEST_CASE("convert_uint8_to_int16_stream {}")
{
    auto uint8_stream = STREAM(uint8_t);
    auto int16_stream = convert_uint8_to_int16_stream(uint8_stream);

    REQUIRE(int16_stream->size() == 0);
}

TEST_CASE("convert_uint8_to_int16_stream {0, 0}")
{
    auto uint8_stream = STREAM(uint8_t, 0, 0);
    auto int16_stream = convert_uint8_to_int16_stream(uint8_stream);

    REQUIRE(int16_stream->size() == 1);
    REQUIRE((*int16_stream)[0] == 0);
}

TEST_CASE("convert_uint8_to_int16_stream {0, 0, 0, 0}")
{
    auto uint8_stream = STREAM(uint8_t, 0, 0, 0, 0);
    auto int16_stream = convert_uint8_to_int16_stream(uint8_stream);

    REQUIRE(int16_stream->size() == 2);
    REQUIRE((*int16_stream)[0] == 0);
    REQUIRE((*int16_stream)[1] == 0);
}

TEST_CASE("convert_uint8_to_int16_stream {1, 0}")
{
    auto uint8_stream = STREAM(uint8_t, 1, 0);
    auto int16_stream = convert_uint8_to_int16_stream(uint8_stream);

    REQUIRE(int16_stream->size() == 1);
    REQUIRE((*int16_stream)[0] == 1);
}

TEST_CASE("convert_uint8_to_int16_stream {0, 1}")
{
    auto uint8_stream = STREAM(uint8_t, 0, 1);
    auto int16_stream = convert_uint8_to_int16_stream(uint8_stream);

    REQUIRE(int16_stream->size() == 1);
    REQUIRE((*int16_stream)[0] == 256);
}

TEST_CASE("convert_uint8_to_int16_stream {1, 1}")
{
    auto uint8_stream = STREAM(uint8_t, 1, 1);
    auto int16_stream = convert_uint8_to_int16_stream(uint8_stream);

    REQUIRE(int16_stream->size() == 1);
    REQUIRE((*int16_stream)[0] == 257);
}

TEST_CASE("convert_uint8_to_int16_stream {0xFF, 0xFF}")
{
    auto uint8_stream = STREAM(uint8_t, 0xFF, 0xFF);
    auto int16_stream = convert_uint8_to_int16_stream(uint8_stream);

    REQUIRE(int16_stream->size() == 1);
    REQUIRE((*int16_stream)[0] == -1);
}

#endif
