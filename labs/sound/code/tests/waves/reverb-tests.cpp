#ifdef TEST_BUILD

#include "Catch.h"
#include "solution/waves/sine-wave-solution.h"
#include "waves/reverb.h"
#include "solution/waves/reverb-solution.h"
#include "tests/testlib.h"


TEST_CASE("reverb(wave, 4, 0.9, 0.1)")
{
    const unsigned n_reverberations = 4;
    const double factor = 0.9;
    const double delay = 0.1;

    auto wave = solution::sine_wave(1, 1, 1);
    auto expected = solution::reverb(wave, n_reverberations, factor, delay);
    auto actual = reverb(wave, n_reverberations, factor, delay);

    check_equal_waves(expected, actual);
}

TEST_CASE("reverb(wave, 3, 0.5, 0.2)")
{
    const unsigned n_reverberations = 3;
    const double factor = 0.5;
    const double delay = 0.2;

    auto wave = solution::sine_wave(1, 1, 1);
    auto expected = solution::reverb(wave, n_reverberations, factor, delay);
    auto actual = reverb(wave, n_reverberations, factor, delay);

    check_equal_waves(expected, actual);
}

#endif
