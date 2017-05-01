#ifdef TEST_BUILD

#include "Catch.h"
#include "waves/wave-concatenation.h"
#include "tests/testlib.h"


TEST_CASE("Wave concatenation of 2 waves")
{
    auto w1 = constant_wave(1, 1);
    auto w2 = constant_wave(1, 2);
    std::vector<Wave> waves = { w1, w2 };
    auto c = concatenate(waves);

    REQUIRE(c.duration() == Approx(2));
    CHECK(c[0] == Approx(1));
    CHECK(c[0.999] == Approx(1));
    CHECK(c[1.001] == Approx(2));
    CHECK(c[1.999] == Approx(2));
}

TEST_CASE("Wave concatenation of 3 waves")
{
    auto w1 = constant_wave(1, 1);
    auto w2 = constant_wave(1, 2);
    auto w3 = constant_wave(1, 3);
    std::vector<Wave> waves = { w1, w2, w3 };
    auto c = concatenate(waves);

    REQUIRE(c.duration() == Approx(3));
    CHECK(c[0] == Approx(1));
    CHECK(c[0.999] == Approx(1));
    CHECK(c[1.001] == Approx(2));
    CHECK(c[1.999] == Approx(2));
    CHECK(c[2.001] == Approx(3));
}

#endif
