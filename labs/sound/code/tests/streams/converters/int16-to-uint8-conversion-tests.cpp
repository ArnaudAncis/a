#ifdef TEST_BUILD

#include "Catch.h"
#include "streams/converters/int16-to-uint8-conversion.h"
#include "tests/testlib.h"


TEST_CASE("convert_int16_to_uint8_stream {}")
{
    auto int16_stream = STREAM(int16_t);
    auto uint8_stream = convert_int16_to_uint8_stream(int16_stream);

    REQUIRE(uint8_stream->size() == 0);
}

TEST_CASE("convert_int16_to_uint8_stream {0}")
{
    auto int16_stream = STREAM(int16_t, 0);
    auto uint8_stream = convert_int16_to_uint8_stream(int16_stream);

    REQUIRE(uint8_stream->size() == 2);
    REQUIRE((*uint8_stream)[0] == 0);
    REQUIRE((*uint8_stream)[1] == 0);
}

TEST_CASE("convert_int16_to_uint8_stream {1}")
{
    auto int16_stream = STREAM(int16_t, 1);
    auto uint8_stream = convert_int16_to_uint8_stream(int16_stream);

    REQUIRE(uint8_stream->size() == 2);
    REQUIRE((*uint8_stream)[0] == 1);
    REQUIRE((*uint8_stream)[1] == 0);
}

TEST_CASE("convert_int16_to_uint8_stream {0, 0}")
{
    auto int16_stream = STREAM(int16_t, 0, 0);
    auto uint8_stream = convert_int16_to_uint8_stream(int16_stream);

    REQUIRE(uint8_stream->size() == 4);
    REQUIRE((*uint8_stream)[0] == 0);
    REQUIRE((*uint8_stream)[1] == 0);
    REQUIRE((*uint8_stream)[2] == 0);
    REQUIRE((*uint8_stream)[3] == 0);
}

TEST_CASE("convert_int16_to_uint8_stream {-1}")
{
    auto int16_stream = STREAM(int16_t, -1);
    auto uint8_stream = convert_int16_to_uint8_stream(int16_stream);

    REQUIRE(uint8_stream->size() == 2);
    REQUIRE((*uint8_stream)[0] == 0xFF);
    REQUIRE((*uint8_stream)[1] == 0xFF);
}

TEST_CASE("convert_int16_to_uint8_stream {32767}")
{
    auto int16_stream = STREAM(int16_t, 32767);
    auto uint8_stream = convert_int16_to_uint8_stream(int16_stream);

    REQUIRE(uint8_stream->size() == 2);
    REQUIRE((*uint8_stream)[0] == 0xFF);
    REQUIRE((*uint8_stream)[1] == 0x7F);
}

TEST_CASE("convert_int16_to_uint8_stream {0, -1, 32767}")
{
    auto int16_stream = STREAM(int16_t, 0, -1, 32767);
    auto uint8_stream = convert_int16_to_uint8_stream(int16_stream);

    REQUIRE(uint8_stream->size() == 6);
    REQUIRE((*uint8_stream)[0] == 0);
    REQUIRE((*uint8_stream)[1] == 0);
    REQUIRE((*uint8_stream)[2] == 0xFF);
    REQUIRE((*uint8_stream)[3] == 0xFF);
    REQUIRE((*uint8_stream)[4] == 0xFF);
    REQUIRE((*uint8_stream)[5] == 0x7F);
}

#endif