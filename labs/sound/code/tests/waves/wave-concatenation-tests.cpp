#ifdef TEST_BUILD

#include "Catch.h"
#include "solution/waves/sine-wave-solution.h"
#include "waves/wave-concatenation.h"
#include "solution/waves/wave-concatenation-solution.h"
#include "tests/testlib.h"


auto sine_wave = solution::sine_wave;

TEST_CASE("Wave concatenation of { sine_wave(1,1,1), sine_wave(1,2,1) }")
{
    std::vector<Wave> waves = { sine_wave(1,1,1), sine_wave(1,2,1) };
    auto expected = solution::concatenate(waves);
    auto actual = concatenate(waves);

    check_equal_waves(expected, actual);
}

TEST_CASE("Wave concatenation of { sine_wave(1,1,1), sine_wave(1,1,2) }")
{
    std::vector<Wave> waves = { sine_wave(1,1,1), sine_wave(1,1,2) };
    auto expected = solution::concatenate(waves);
    auto actual = concatenate(waves);

    check_equal_waves(expected, actual);
}

TEST_CASE("Wave concatenation of { sine_wave(1,1,1), sine_wave(2,2,2) }")
{
    std::vector<Wave> waves = { sine_wave(1,1,1), sine_wave(2,2,2) };
    auto expected = solution::concatenate(waves);
    auto actual = concatenate(waves);

    check_equal_waves(expected, actual);
}

TEST_CASE("Wave concatenation of { sine_wave(1,1,1), sine_wave(2,2,2), sine_wave(3,3,3) }")
{
    std::vector<Wave> waves = { sine_wave(1,1,1), sine_wave(2,2,2), sine_wave(3,3,3) };
    auto expected = solution::concatenate(waves);
    auto actual = concatenate(waves);

    check_equal_waves(expected, actual);
}

#endif
