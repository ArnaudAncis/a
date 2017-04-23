#ifdef TEST_BUILD

#include "Catch.h"
#include "waves/wave-sampling-stream.h"
#include "solution/waves/sine-wave-solution.h"
#include "solution/waves/wave-sampling-stream-solution.h"
#include "tests/testlib.h"


TEST_CASE("Sampling sine wave at 10Hz")
{
    const unsigned sample_rate = 10;
    auto wave = solution::sine_wave(5, 4, 9);
    auto expected = solution::sample_wave(wave, sample_rate);
    auto actual = sample_wave(wave, sample_rate);

    check_equal_streams(expected, actual);
}

TEST_CASE("Sampling sine wave at 25Hz")
{
    const unsigned sample_rate = 25;
    auto wave = solution::sine_wave(5, 4, 9);
    auto expected = solution::sample_wave(wave, sample_rate);
    auto actual = sample_wave(wave, sample_rate);

    check_equal_streams(expected, actual);
}

TEST_CASE("Sampling sine wave at 1234Hz")
{
    const unsigned sample_rate = 1234;
    auto wave = solution::sine_wave(5, 4, 9);
    auto expected = solution::sample_wave(wave, sample_rate);
    auto actual = sample_wave(wave, sample_rate);

    check_equal_streams(expected, actual);
}

#endif
