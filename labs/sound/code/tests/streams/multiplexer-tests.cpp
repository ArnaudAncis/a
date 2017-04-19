#ifdef TEST_BUILD

#include "streams/multiplexer.h"
 #include "tests/testlib.h"
 #include "Catch.h"


TEST_CASE("multiplexing {} and {}")
{
    auto s1 = STREAM(int);
    auto s2 = STREAM(int);
    auto s = multiplex<int>(s1, s2);

    REQUIRE(s->size() == 0);
}

TEST_CASE("multiplexing {1} and {2}")
{
    auto s1 = STREAM(int, 1);
    auto s2 = STREAM(int, 2);
    auto s = multiplex<int>(s1, s2);

    REQUIRE(s->size() == 2);
    REQUIRE((*s)[0] == 1);
    REQUIRE((*s)[1] == 2);
}

TEST_CASE("multiplexing {1, 3} and {2, 4}")
{
    auto s1 = STREAM(int, 1, 3);
    auto s2 = STREAM(int, 2, 4);
    auto s = multiplex<int>(s1, s2);

    REQUIRE(s->size() == 4);
    REQUIRE((*s)[0] == 1);
    REQUIRE((*s)[1] == 2);
    REQUIRE((*s)[2] == 3);
    REQUIRE((*s)[3] == 4);
}

TEST_CASE("multiplexing {1.0, 8.0} and {7.0, 6.0}")
{
    auto s1 = STREAM(double, 1.0, 8.0);
    auto s2 = STREAM(double, 7.0, 6.0);
    auto s = multiplex<double>(s1, s2);

    REQUIRE(s->size() == 4);
    REQUIRE((*s)[0] == 1.0);
    REQUIRE((*s)[1] == 7.0);
    REQUIRE((*s)[2] == 8.0);
    REQUIRE((*s)[3] == 6.0);
}

#endif
