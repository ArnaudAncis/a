#include <vector>

void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}


/*

TESTS

*/

#define CATCH_CONFIG_MAIN
#include "Catch.h"

void test(int x, int y)
{
    int original_x = x;
    int original_y = y;

    int swapped_x = x;
    int swapped_y = y;

    swap(swapped_x, swapped_y);

    REQUIRE(swapped_x == original_y);
    REQUIRE(swapped_y == original_x);
}

#define TEST(x, y) TEST_CASE("swap( " #x ", " #y ")", "[swap]") { test(x, y); }

TEST(0, 0)
TEST(0, 1)
TEST(1, 0)
TEST(5, -5)
