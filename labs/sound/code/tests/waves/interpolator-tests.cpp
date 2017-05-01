#ifdef TEST_BUILD

#include "Catch.h"
#include "waves/interpolator.h"
#include "tests/testlib.h"


TEST_CASE("interpolator {0, 0} with sample rate 1")
{
    auto wave = interpolate(STREAM(double, 0, 0), 1);

    REQUIRE(wave.duration() == Approx(1));
    REQUIRE(wave[0] == Approx(0));
    REQUIRE(wave[0.1] == Approx(0));
    REQUIRE(wave[0.2] == Approx(0));
    REQUIRE(wave[0.3] == Approx(0));
    REQUIRE(wave[0.4] == Approx(0));
    REQUIRE(wave[0.5] == Approx(0));
    REQUIRE(wave[0.6] == Approx(0));
    REQUIRE(wave[0.7] == Approx(0));
    REQUIRE(wave[0.8] == Approx(0));
    REQUIRE(wave[0.9] == Approx(0));
    REQUIRE(wave[0.999] == Approx(0));
}

TEST_CASE("interpolator {0, 0, 0} with sample rate 2")
{
    auto wave = interpolate(STREAM(double, 0, 0, 0), 2);

    REQUIRE(wave.duration() == Approx(1));
    REQUIRE(wave[0] == Approx(0));
    REQUIRE(wave[0.1] == Approx(0));
    REQUIRE(wave[0.2] == Approx(0));
    REQUIRE(wave[0.3] == Approx(0));
    REQUIRE(wave[0.4] == Approx(0));
    REQUIRE(wave[0.5] == Approx(0));
    REQUIRE(wave[0.6] == Approx(0));
    REQUIRE(wave[0.7] == Approx(0));
    REQUIRE(wave[0.8] == Approx(0));
    REQUIRE(wave[0.9] == Approx(0));
    REQUIRE(wave[0.999] == Approx(0));
}

TEST_CASE("interpolator {0, 1} with sample rate 1")
{
    auto wave = interpolate(STREAM(double, 0, 1), 1);

    REQUIRE(wave.duration() == Approx(1));
    REQUIRE(wave[0] == Approx(0));
    REQUIRE(wave[0.1] == Approx(0.1));
    REQUIRE(wave[0.2] == Approx(0.2));
    REQUIRE(wave[0.3] == Approx(0.3));
    REQUIRE(wave[0.4] == Approx(0.4));
    REQUIRE(wave[0.5] == Approx(0.5));
    REQUIRE(wave[0.6] == Approx(0.6));
    REQUIRE(wave[0.7] == Approx(0.7));
    REQUIRE(wave[0.8] == Approx(0.8));
    REQUIRE(wave[0.9] == Approx(0.9));
    REQUIRE(wave[0.999] == Approx(0.999));
}

TEST_CASE("interpolator {0, 1, 0} with sample rate 1")
{
    auto wave = interpolate(STREAM(double, 0, 1, 0), 1);

    REQUIRE(wave.duration() == Approx(2));
    REQUIRE(wave[0] == Approx(0));
    REQUIRE(wave[0.1] == Approx(0.1));
    REQUIRE(wave[0.2] == Approx(0.2));
    REQUIRE(wave[0.3] == Approx(0.3));
    REQUIRE(wave[0.4] == Approx(0.4));
    REQUIRE(wave[0.5] == Approx(0.5));
    REQUIRE(wave[0.6] == Approx(0.6));
    REQUIRE(wave[0.7] == Approx(0.7));
    REQUIRE(wave[0.8] == Approx(0.8));
    REQUIRE(wave[0.9] == Approx(0.9));
    REQUIRE(wave[1] == Approx(1));
    REQUIRE(wave[1.2] == Approx(0.8));
    REQUIRE(wave[1.4] == Approx(0.6));
    REQUIRE(wave[1.6] == Approx(0.4));
    REQUIRE(wave[1.8] == Approx(0.2));
}

TEST_CASE("interpolator {1, 0} with sample rate 1")
{
    auto wave = interpolate(STREAM(double, 1, 0), 1);

    REQUIRE(wave.duration() == Approx(1));
    REQUIRE(wave[0] == Approx(1));
    REQUIRE(wave[0.1] == Approx(1 - 0.1));
    REQUIRE(wave[0.2] == Approx(1 - 0.2));
    REQUIRE(wave[0.3] == Approx(1 - 0.3));
    REQUIRE(wave[0.4] == Approx(1 - 0.4));
    REQUIRE(wave[0.5] == Approx(1 - 0.5));
    REQUIRE(wave[0.6] == Approx(1 - 0.6));
    REQUIRE(wave[0.7] == Approx(1 - 0.7));
    REQUIRE(wave[0.8] == Approx(1 - 0.8));
    REQUIRE(wave[0.9] == Approx(1 - 0.9));
}

#endif
