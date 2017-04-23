#ifdef TEST_BUILD

#include "Catch.h"
#include "waves/square-wave.h"
#include "solution/waves/square-wave-solution.h"
#include "tests/testlib.h"


TEST_CASE("Length of square wave of length 5s")
{
    auto wave = square_wave(5, 1, 1);

    REQUIRE(wave.length() == Approx(5));
}

TEST_CASE("Manual sampling square wave with frequency 1 and amplitude 1")
{
    const double length = 10;
    const double amplitude = 1;
    const double frequency = 1;

    auto wave = square_wave(length, amplitude, frequency);

    CHECK(wave[0.01] == Approx(1));
    CHECK(wave[0.25] == Approx(1));
    CHECK(wave[0.49] == Approx(1));
    CHECK(wave[0.51] == Approx(-1));
    CHECK(wave[0.75] == Approx(-1));
    CHECK(wave[0.99] == Approx(-1));
}

TEST_CASE("Sampling square wave with frequency 1 and amplitude 1")
{
    const double length = 10;
    const double amplitude = 1;
    const double frequency = 1;

    auto expected = solution::square_wave(length, amplitude, frequency);
    auto wave = square_wave(length, amplitude, frequency);

    check_equal_waves(expected, wave);
}

TEST_CASE("Sampling square wave with frequency 1 and amplitude 2")
{
    const double length = 10;
    const double amplitude = 2;
    const double frequency = 1;

    auto expected = solution::square_wave(length, amplitude, frequency);
    auto wave = square_wave(length, amplitude, frequency);

    check_equal_waves(expected, wave);
}

TEST_CASE("Sampling square wave with frequency 2 and amplitude 1")
{
    const double length = 10;
    const double amplitude = 1;
    const double frequency = 2;

    auto expected = solution::square_wave(length, amplitude, frequency);
    auto wave = square_wave(length, amplitude, frequency);

    check_equal_waves(expected, wave);
}

TEST_CASE("Sampling square wave with frequency 4 and amplitude 6")
{
    const double length = 10;
    const double amplitude = 4;
    const double frequency = 6;

    auto expected = solution::square_wave(length, amplitude, frequency);
    auto wave = square_wave(length, amplitude, frequency);

    check_equal_waves(expected, wave);
}

#endif
