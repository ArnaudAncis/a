#ifdef TEST_BUILD

#include "Catch.h"
#include "waves/square-wave.h"
#include "tests/testlib.h"


TEST_CASE("duration of square wave of duration 5s")
{
    auto wave = square_wave(5, 1, 1);

    REQUIRE(wave.duration() == Approx(5));
}

TEST_CASE("Sampling square wave with frequency 1 and amplitude 1")
{
    const double duration = 10;
    const double amplitude = 1;
    const double frequency = 1;

    auto wave = square_wave(duration, amplitude, frequency);

    CHECK(wave[0.01] == Approx(1));
    CHECK(wave[0.25] == Approx(1));
    CHECK(wave[0.49] == Approx(1));
    CHECK(wave[0.51] == Approx(-1));
    CHECK(wave[0.75] == Approx(-1));
    CHECK(wave[0.99] == Approx(-1));
}

TEST_CASE("Sampling square wave with frequency 1 and amplitude 2")
{
    const double duration = 10;
    const double amplitude = 2;
    const double frequency = 1;

    auto wave = square_wave(duration, amplitude, frequency);

    CHECK(wave[0.01] == Approx(2));
    CHECK(wave[0.25] == Approx(2));
    CHECK(wave[0.49] == Approx(2));
    CHECK(wave[0.51] == Approx(-2));
    CHECK(wave[0.75] == Approx(-2));
    CHECK(wave[0.99] == Approx(-2));
}

TEST_CASE("Sampling square wave with frequency 2 and amplitude 1")
{
    const double duration = 10;
    const double amplitude = 1;
    const double frequency = 2;

    auto wave = square_wave(duration, amplitude, frequency);

    CHECK(wave[0.01] == Approx(1));
    CHECK(wave[0.125] == Approx(1));
    CHECK(wave[0.249] == Approx(1));
    CHECK(wave[0.251] == Approx(-1));
    CHECK(wave[0.375] == Approx(-1));
    CHECK(wave[0.499] == Approx(-1));
}

#endif
