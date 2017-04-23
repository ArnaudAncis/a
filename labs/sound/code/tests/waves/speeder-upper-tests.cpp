#ifdef TEST_BUILD

#include "Catch.h"
#include "solution/waves/sine-wave-solution.h"
#include "waves/speeder-upper.h"
#include "solution/waves/speeder-upper-solution.h"
#include "tests/testlib.h"


TEST_CASE("Speeding up wave of length 10 by factor 10 yields wave of length 1")
{
    auto wave = solution::sine_wave(10, 1, 1);
    auto actual = speed_up(wave, 10);

    REQUIRE(actual.length() == Approx(1));
}

TEST_CASE("Speeding up sine(1,1,1) by factor 2")
{
    const double factor = 2;
    auto wave = solution::sine_wave(1, 1, 1);
    
    auto expected = solution::speed_up(wave, factor);
    auto actual = speed_up(wave, factor);

    check_equal_waves(expected, actual);
}

TEST_CASE("Speeding up sine(2,1,1) by factor 2")
{
    const double factor = 2;
    auto wave = solution::sine_wave(2, 1, 1);

    auto expected = solution::speed_up(wave, factor);
    auto actual = speed_up(wave, factor);

    check_equal_waves(expected, actual);
}

TEST_CASE("Speeding up sine(1,2,1) by factor 3")
{
    const double factor = 3;
    auto wave = solution::sine_wave(1, 2, 1);

    auto expected = solution::speed_up(wave, factor);
    auto actual = speed_up(wave, factor);

    check_equal_waves(expected, actual);
}

TEST_CASE("Speeding up sine(1,1,3) by factor 4")
{
    const double factor = 4;
    auto wave = solution::sine_wave(1, 1, 3);

    auto expected = solution::speed_up(wave, factor);
    auto actual = speed_up(wave, factor);

    check_equal_waves(expected, actual);
}

#endif
