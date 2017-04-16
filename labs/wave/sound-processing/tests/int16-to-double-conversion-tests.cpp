#include "Catch.h"
#include "streams/conversions.h"
#include "tests/testlib.h"


TEST_CASE("convert_int16_to_double_stream {}")
{
    auto int16_stream = STREAM(int16_t);
    auto double_stream = convert_int16_to_double_stream(int16_stream);

    REQUIRE(double_stream->size() == 0);
}

TEST_CASE("convert_int16_to_double_stream {0}")
{
    auto int16_stream = STREAM(int16_t, 0);
    auto double_stream = convert_int16_to_double_stream(int16_stream);

    REQUIRE(double_stream->size() == 1);
    REQUIRE((*double_stream)[0] == 0);
}

TEST_CASE("convert_int16_to_double_stream {0, 0}")
{
    auto int16_stream = STREAM(int16_t, 0, 0);
    auto double_stream = convert_int16_to_double_stream(int16_stream);

    REQUIRE(double_stream->size() == 2);
    REQUIRE((*double_stream)[0] == 0);
    REQUIRE((*double_stream)[1] == 0);
}

TEST_CASE("convert_int16_to_double_stream {32767}")
{
    auto int16_stream = STREAM(int16_t, 32767);
    auto double_stream = convert_int16_to_double_stream(int16_stream);

    REQUIRE(double_stream->size() == 1);
    REQUIRE((*double_stream)[0] == Approx(1));
}

TEST_CASE("convert_int16_to_double_stream {-32767}")
{
    auto int16_stream = STREAM(int16_t, -32767);
    auto double_stream = convert_int16_to_double_stream(int16_stream);

    REQUIRE(double_stream->size() == 1);
    REQUIRE((*double_stream)[0] == Approx(-1).epsilon(0.0001));
}
