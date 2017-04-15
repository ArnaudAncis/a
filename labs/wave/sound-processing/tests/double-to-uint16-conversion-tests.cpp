#include "Catch.h"
#include "streams/conversions.h"
#include "tests/testlib.h"


TEST_CASE("convert_double_to_int16_stream {}")
{
    auto double_stream = STREAM(double);
    auto int16_stream = convert_double_to_int16_stream(double_stream);

    REQUIRE(int16_stream->size() == 0);
}

TEST_CASE("convert_double_to_int16_stream {0}")
{
    auto double_stream = STREAM(double, { 0 });
    auto int16_stream = convert_double_to_int16_stream(double_stream);

    REQUIRE(int16_stream->size() == 1);
    REQUIRE((*int16_stream)[0] == 0);
}

TEST_CASE("convert_double_to_int16_stream {1}")
{
    auto double_stream = STREAM(double, { 1 });
    auto int16_stream = convert_double_to_int16_stream(double_stream);

    REQUIRE(int16_stream->size() == 1);
    REQUIRE((*int16_stream)[0] == 32767);
}

TEST_CASE("convert_double_to_int16_stream {-1}")
{
    auto double_stream = STREAM(double, { -1 });
    auto int16_stream = convert_double_to_int16_stream(double_stream);

    REQUIRE(int16_stream->size() == 1);
    REQUIRE((*int16_stream)[0] == -32767);
}

TEST_CASE("convert_double_to_int16_stream {0, 0, 0}")
{
    auto double_stream = STREAM(double, { 0, 0, 0 });
    auto int16_stream = convert_double_to_int16_stream(double_stream);

    REQUIRE(int16_stream->size() == 3);
    REQUIRE((*int16_stream)[0] == 0);
    REQUIRE((*int16_stream)[1] == 0);
    REQUIRE((*int16_stream)[2] == 0);
}