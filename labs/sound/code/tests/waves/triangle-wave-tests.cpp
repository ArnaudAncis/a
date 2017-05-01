#ifdef TEST_BUILD

#include "Catch.h"
#include "waves/triangle-wave.h"
#include "tests/testlib.h"


TEST_CASE("duration of triangle wave of duration 5s")
{
    auto wave = triangle_wave(5, 1, 1);

    REQUIRE(wave.duration() == Approx(5));
}

TEST_CASE("Sampling triangle wave with frequency 1 and amplitude 1")
{
    const double duration = 10;
    const double amplitude = 1;
    const double frequency = 1;

    auto wave = triangle_wave(duration, amplitude, frequency);
 
    CHECK(wave[0.0] == Approx(0));
    CHECK(wave[0.125] == Approx(0.5));
    CHECK(wave[0.25] == Approx(1));
    CHECK(wave[0.375] == Approx(0.5));
    CHECK(wave[0.5] == Approx(0));
    CHECK(wave[0.625] == Approx(-0.5));
    CHECK(wave[0.75] == Approx(-1));
    CHECK(wave[0.875] == Approx(-0.5));
    CHECK(wave[1.0] == Approx(0));
}

TEST_CASE("Sampling triangle wave with frequency 1 and amplitude 2")
{
    const double duration = 10;
    const double amplitude = 2;
    const double frequency = 1;

    auto wave = triangle_wave(duration, amplitude, frequency);

    CHECK(wave[0.0] == Approx(0));
    CHECK(wave[0.25] == Approx(2));
    CHECK(wave[0.5] == Approx(0));
    CHECK(wave[0.75] == Approx(-2));
    CHECK(wave[1.0] == Approx(0));
}

TEST_CASE("Sampling triangle wave with frequency 2 and amplitude 1")
{
    const double duration = 10;
    const double amplitude = 1;
    const double frequency = 2;

    auto wave = triangle_wave(duration, amplitude, frequency);

    CHECK(wave[0.0] == Approx(0));
    CHECK(wave[0.125] == Approx(1));
    CHECK(wave[0.25] == Approx(0));
    CHECK(wave[0.375] == Approx(-1));
    CHECK(wave[0.5] == Approx(0));
}

#endif
