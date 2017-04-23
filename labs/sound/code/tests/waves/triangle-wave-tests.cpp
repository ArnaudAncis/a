#ifdef TEST_BUILD

#include "Catch.h"
#include "waves/triangle-wave.h"
#include "solution/waves/triangle-wave-solution.h"
#include "tests/testlib.h"


TEST_CASE("Length of triangle wave of length 5s")
{
    auto wave = triangle_wave(5, 1, 1);

    REQUIRE(wave.length() == Approx(5));
}

TEST_CASE("Sampling triangle wave with frequency 1 and amplitude 1")
{
    const double length = 10;
    const double amplitude = 1;
    const double frequency = 1;

    auto expected = solution::triangle_wave(length, amplitude, frequency);
    auto wave = triangle_wave(length, amplitude, frequency);

    check_same_wave(expected, wave);
}

TEST_CASE("Sampling triangle wave with frequency 1 and amplitude 2")
{
    const double length = 10;
    const double amplitude = 2;
    const double frequency = 1;

    auto expected = solution::triangle_wave(length, amplitude, frequency);
    auto wave = triangle_wave(length, amplitude, frequency);

    check_same_wave(expected, wave);
}

TEST_CASE("Sampling triangle wave with frequency 2 and amplitude 1")
{
    const double length = 10;
    const double amplitude = 1;
    const double frequency = 2;

    auto expected = solution::triangle_wave(length, amplitude, frequency);
    auto wave = triangle_wave(length, amplitude, frequency);

    check_same_wave(expected, wave);
}

TEST_CASE("Sampling triangle wave with frequency 4 and amplitude 6")
{
    const double length = 10;
    const double amplitude = 4;
    const double frequency = 6;

    auto expected = solution::triangle_wave(length, amplitude, frequency);
    auto wave = triangle_wave(length, amplitude, frequency);

    check_same_wave(expected, wave);
}

#endif
