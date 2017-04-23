#ifdef TEST_BUILD

#include "Catch.h"
#include "waves/sine-wave.h"
#include "solution/waves/sine-wave-solution.h"
#include "tests/testlib.h"


TEST_CASE("Length of sine wave of length 5s")
{
    auto wave = sine_wave(5, 1, 1);

    REQUIRE(wave.length() == Approx(5));
}

TEST_CASE("Sampling sine wave with frequency 1 and amplitude 1")
{
    const double length = 10;
    const double amplitude = 1;
    const double frequency = 1;

    auto expected = solution::sine_wave(length, amplitude, frequency);
    auto wave = sine_wave(length, amplitude, frequency);

    check_equal_waves(expected, wave);
}

TEST_CASE("Sampling sine wave with frequency 1 and amplitude 2")
{
    const double length = 10;
    const double amplitude = 2;
    const double frequency = 1;

    auto expected = solution::sine_wave(length, amplitude, frequency);
    auto wave = sine_wave(length, amplitude, frequency);

    check_equal_waves(expected, wave);
}

TEST_CASE("Sampling sine wave with frequency 2 and amplitude 1")
{
    const double length = 10;
    const double amplitude = 1;
    const double frequency = 2;

    auto expected = solution::sine_wave(length, amplitude, frequency);
    auto wave = sine_wave(length, amplitude, frequency);

    check_equal_waves(expected, wave);
}

TEST_CASE("Sampling sine wave with frequency 4 and amplitude 6")
{
    const double length = 10;
    const double amplitude = 4;
    const double frequency = 6;

    auto expected = solution::sine_wave(length, amplitude, frequency);
    auto wave = sine_wave(length, amplitude, frequency);

    check_equal_waves(expected, wave);
}

#endif
