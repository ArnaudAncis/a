#include <limits>
#include <vector>
#include <array>

void minmax(const int* ns, int length, int* min, int* max)
{
    // TODO
}

void minmax(const std::vector<int>* ns, int* min, int* max)
{
    // TODO
}

template<unsigned N>
void minmax(const std::array<int, N>* ns, int* min, int* max)
{
    // TODO
}


/*

    TESTS

*/

#define CATCH_CONFIG_MAIN
#include "Catch.h"

void c_style_test(const int* ns, int size, int expected_min, int expected_max)
{
    int min, max;

    minmax(ns, size, &min, &max);

    REQUIRE(min == expected_min);
    REQUIRE(max == expected_max);
}

template<unsigned N>
void cpp_style_test(const std::array<int, N>& ns, int expected_min, int expected_max)
{
    int min, max;

    minmax(&ns, &min, &max);

    REQUIRE(min == expected_min);
    REQUIRE(max == expected_max);
}

void vector_test(const std::vector<int>& ns, int expected_min, int expected_max)
{
    int min, max;

    minmax(&ns, &min, &max);

    REQUIRE(min == expected_min);
    REQUIRE(max == expected_max);
}

#define C_STYLE_TEST(expected_min, expected_max, ...) TEST_CASE("minmax on C-style array { " #__VA_ARGS__ " }, expected min=" #expected_min ", max=" #expected_max, "[minmax]") { int ns[] = { __VA_ARGS__ }; c_style_test(ns, sizeof(ns) / sizeof(int), expected_min, expected_max); }
#define CPP_STYLE_TEST(expected_min, expected_max, ...) TEST_CASE("minmax on C++-style array { " #__VA_ARGS__ " }, expected min=" #expected_min ", max=" #expected_max, "[minmax]") { int arr[] = { __VA_ARGS__ }; std::array<int, sizeof(arr)/sizeof(int)> ns = { __VA_ARGS__ }; cpp_style_test(ns, expected_min, expected_max); }
#define VECTOR_TEST(expected_min, expected_max, ...) TEST_CASE("minmax on vector { " #__VA_ARGS__ " }, expected min=" #expected_min ", max=" #expected_max, "[minmax]") { std::vector<int> ns = { __VA_ARGS__ }; vector_test(ns, expected_min, expected_max); }


C_STYLE_TEST(1, 1, 1)
C_STYLE_TEST(1, 1, 1, 1)
C_STYLE_TEST(1, 2, 1, 2)
C_STYLE_TEST(1, 2, 2, 1)
C_STYLE_TEST(0, 2, 2, 0, 1)
C_STYLE_TEST(1, 9, 5, 7, 1, 5, 8, 4, 6, 2, 3, 8, 7, 4, 9)

CPP_STYLE_TEST(1, 1, 1)
CPP_STYLE_TEST(1, 1, 1, 1)
CPP_STYLE_TEST(1, 2, 1, 2)
CPP_STYLE_TEST(1, 2, 2, 1)
CPP_STYLE_TEST(0, 2, 2, 0, 1)
CPP_STYLE_TEST(1, 9, 5, 7, 1, 5, 8, 4, 6, 2, 3, 8, 7, 4, 9)

VECTOR_TEST(1, 1, 1)
VECTOR_TEST(1, 1, 1, 1)
VECTOR_TEST(1, 2, 1, 2)
VECTOR_TEST(1, 2, 2, 1)
VECTOR_TEST(0, 2, 2, 0, 1)
VECTOR_TEST(1, 9, 5, 7, 1, 5, 8, 4, 6, 2, 3, 8, 7, 4, 9)