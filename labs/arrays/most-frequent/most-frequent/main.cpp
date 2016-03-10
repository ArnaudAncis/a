#include <vector>

int most_frequent(const std::vector<int>* ns)
{
    // TODO
}


/*

TESTS

*/

#define CATCH_CONFIG_MAIN
#include "Catch.h"

void test(const std::vector<int>& ns, int expected)
{
    int actual = most_frequent(&ns);

    REQUIRE(expected == actual);
}

#define TEST(expected, ...) TEST_CASE("minmax on { " #__VA_ARGS__ " }, expected=" #expected, "[most_frequent]") { std::vector<int> ns = { __VA_ARGS__}; test(ns, expected); }

TEST(-1)
TEST(0, 0)
TEST(1, 1)
TEST(2, 2)
TEST(1, 0, 1, 1)
TEST(0, 1, 0, 0)
TEST(1, 0, 1, 2, 1)
TEST(3, 1, 2, 3, 3, 4, 5)
TEST(3, 3, 1, 2, 3, 4, 5)