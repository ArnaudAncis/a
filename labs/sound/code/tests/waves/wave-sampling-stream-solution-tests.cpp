#ifdef TEST_BUILD

#include "Catch.h"
#include "waves/wave-sampling-stream.h"
#include "tests/testlib.h"


TEST_CASE("Sampling wave at 1Hz")
{
    const unsigned sample_rate = 1;
    auto wave = linear_wave(10, 1, 0);
    auto actual = sample_wave(wave, sample_rate);

    REQUIRE(actual->size() == 10);
    CHECK((*actual)[0] == Approx(0));
    CHECK((*actual)[1] == Approx(1));
    CHECK((*actual)[2] == Approx(2));
    CHECK((*actual)[3] == Approx(3));
    CHECK((*actual)[4] == Approx(4));
    CHECK((*actual)[5] == Approx(5));
    CHECK((*actual)[6] == Approx(6));
    CHECK((*actual)[7] == Approx(7));
    CHECK((*actual)[8] == Approx(8));
    CHECK((*actual)[9] == Approx(9));
}

TEST_CASE("Sampling wave at 10Hz")
{
    const unsigned sample_rate = 10;
    auto wave = linear_wave(1, 10, 0);
    auto actual = sample_wave(wave, sample_rate);

    REQUIRE(actual->size() == 10);
    CHECK((*actual)[0] == Approx(0));
    CHECK((*actual)[1] == Approx(1));
    CHECK((*actual)[2] == Approx(2));
    CHECK((*actual)[3] == Approx(3));
    CHECK((*actual)[4] == Approx(4));
    CHECK((*actual)[5] == Approx(5));
    CHECK((*actual)[6] == Approx(6));
    CHECK((*actual)[7] == Approx(7));
    CHECK((*actual)[8] == Approx(8));
    CHECK((*actual)[9] == Approx(9));
}

#endif
