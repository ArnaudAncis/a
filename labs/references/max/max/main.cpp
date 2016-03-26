#include <vector>


// TODO



/*

TESTS

*/

#define CATCH_CONFIG_MAIN
#include "Catch.h"

void test(std::vector<int> ns, int index)
{
    std::vector<int> copy = ns;

    int& max = ::max(ns);

    for (int i = 0; i != ns.size(); ++i)
    {
        REQUIRE(ns[i] == copy[i]);
    }

    max++;

    for (int i = 0; i != ns.size(); ++i)
    {
        if (i != index)
        {
            REQUIRE(ns[i] == copy[i]);
        }
        else
        {
            REQUIRE(ns[i] == copy[i] + 1);
        }
    }
}

#define ARRAY(...) { __VA_ARGS__ }
#define TEST(ns, index) TEST_CASE("max( " #ns ")", "[max]") { std::vector<int> vector = ns; test(vector, index); }

TEST(ARRAY(0), 0)
TEST(ARRAY(1), 0)
TEST(ARRAY(1, 0), 0)
TEST(ARRAY(1, 0, 0, 0), 0)
TEST(ARRAY(1, 0, 0, 0, 1), 0)
TEST(ARRAY(0, 1), 1)
TEST(ARRAY(0, 1, 0, 0, 0), 1)
TEST(ARRAY(0, 1, 0, 1, 0), 1)
TEST(ARRAY(-10, -100, -1), 2)
TEST(ARRAY(-500, -501, -502), 0)
TEST(ARRAY(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21), 20)
