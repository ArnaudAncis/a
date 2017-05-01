#ifdef TEST_BUILD

#include "Catch.h"
#include "waves/reverb.h"
#include "tests/testlib.h"




TEST_CASE("reverb(wave, 2, 0.5, 1)")
{
    const unsigned n_reverberations = 2;
    const double factor = 0.5;
    const double delay = 1;

    auto wave = constant_wave(10, 1);
    auto actual = reverb(wave, n_reverberations, factor, delay);

    REQUIRE(actual.duration() == Approx(11));
    CHECK(actual[0] == Approx(1));
    CHECK(actual[0.999] == Approx(1));
    CHECK(actual[1.001] == Approx(1.5));
    CHECK(actual[2] == Approx(1.5));
    CHECK(actual[3] == Approx(1.5));
}

TEST_CASE("reverb(wave, 3, 0.5, 1)")
{
    const unsigned n_reverberations = 3;
    const double factor = 0.5;
    const double delay = 1;

    auto wave = constant_wave(10, 1);
    auto actual = reverb(wave, n_reverberations, factor, delay);

    REQUIRE(actual.duration() == Approx(12));
    CHECK(actual[0] == Approx(1));
    CHECK(actual[0.999] == Approx(1));
    CHECK(actual[1.001] == Approx(1.5));
    CHECK(actual[1.999] == Approx(1.5));
    CHECK(actual[2.001] == Approx(1.75));
    CHECK(actual[3] == Approx(1.75));
}

TEST_CASE("reverb(wave, 3, 1, 1)")
{
    const unsigned n_reverberations = 3;
    const double factor = 1;
    const double delay = 1;

    auto wave = constant_wave(10, 1);
    auto actual = reverb(wave, n_reverberations, factor, delay);

    REQUIRE(actual.duration() == Approx(12));
    CHECK(actual[0] == Approx(1));
    CHECK(actual[0.999] == Approx(1));
    CHECK(actual[1.001] == Approx(2));
    CHECK(actual[1.999] == Approx(2));
    CHECK(actual[2.001] == Approx(3));
    CHECK(actual[3] == Approx(3));
}

TEST_CASE("reverb(wave, 3, 0.5, 2)")
{
    const unsigned n_reverberations = 3;
    const double factor = 0.5;
    const double delay = 2;

    auto wave = constant_wave(10, 1);
    auto actual = reverb(wave, n_reverberations, factor, delay);

    REQUIRE(actual.duration() == Approx(14));
    CHECK(actual[0] == Approx(1));
    CHECK(actual[1.999] == Approx(1));
    CHECK(actual[2.001] == Approx(1.5));
    CHECK(actual[3.999] == Approx(1.5));
    CHECK(actual[4.001] == Approx(1.75));
    CHECK(actual[5] == Approx(1.75));
}

#endif
