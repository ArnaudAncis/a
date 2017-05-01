#ifdef TEST_BUILD

#include "Catch.h"
#include "waves/speeder-upper.h"
#include "tests/testlib.h"


TEST_CASE("Speeding up wave by factor 10")
{
    auto wave = linear_wave(20, 1, 0);
    auto actual = speed_up(wave, 10);

    REQUIRE(actual.duration() == Approx(2));
    CHECK(actual[0] == Approx(0));
    CHECK(actual[0.1] == Approx(1));
    CHECK(actual[0.5] == Approx(5));
    CHECK(actual[1] == Approx(10));
}

TEST_CASE("Speeding up wave by factor 5")
{
    auto wave = linear_wave(20, 1, 1);
    auto actual = speed_up(wave, 5);

    REQUIRE(actual.duration() == Approx(4));
    CHECK(actual[0] == 1);
    CHECK(actual[1] == 6);
}

#endif
