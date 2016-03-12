#include <vector>

void bitsort(std::vector<unsigned>* ns)
{
    // TODO
}


/*

TESTS

*/

#define CATCH_CONFIG_MAIN
#include "Catch.h"

void test(std::vector<unsigned>& array, std::vector<unsigned>& expected)
{
    bitsort(&array);

    REQUIRE(array.size() == expected.size());

    for (unsigned i = 0; i != array.size(); ++i)
    {
        REQUIRE(array[i] == expected[i]);
    }
}

#define ARRAY(...) { __VA_ARGS__ }
#define TEST(input, output) TEST_CASE("bitsort on " #input ", expected " #output, "[bitsort]") { std::vector<unsigned> array = input; std::vector<unsigned> expected = output; test(array, expected); }

TEST(ARRAY(), ARRAY())
TEST(ARRAY(0), ARRAY(0))
TEST(ARRAY(1), ARRAY(1))
TEST(ARRAY(0, 1), ARRAY(0, 1))
TEST(ARRAY(1, 0), ARRAY(0, 1))
TEST(ARRAY(0, 0, 0), ARRAY(0, 0, 0))
TEST(ARRAY(0, 0, 1), ARRAY(0, 0, 1))
TEST(ARRAY(0, 1, 0), ARRAY(0, 0, 1))
TEST(ARRAY(1, 0, 0), ARRAY(0, 0, 1))
TEST(ARRAY(1, 1, 0), ARRAY(0, 1, 1))
TEST(ARRAY(1, 0, 1), ARRAY(0, 1, 1))
TEST(ARRAY(0, 1, 1), ARRAY(0, 1, 1))
TEST(ARRAY(0, 1, 0, 1, 0, 1), ARRAY(0, 0, 0, 1, 1, 1))
TEST(ARRAY(1, 1, 0, 0, 0, 0), ARRAY(0, 0, 0, 0, 1, 1))
TEST(ARRAY(1, 1, 0, 1, 0, 1, 1), ARRAY(0, 0, 1, 1, 1, 1, 1))