#include <vector>
#include <set>

int lone_wolf(const std::vector<unsigned>* ns)
{
    std::set<unsigned> set;

    for (unsigned n : *ns)
    {
        auto n_position = set.find(n);

        if (n_position == set.end())
        {
            set.insert(n);
        }
        else
        {
            set.erase(n_position);
        }
    }

    return *set.begin();
}


/*

TESTS

*/

#define CATCH_CONFIG_MAIN
#include "Catch.h"

void test(const std::vector<unsigned>& ns, unsigned expected)
{
    int actual = lone_wolf(&ns);

    REQUIRE(actual == expected);
}

#define TEST(expected, ...) TEST_CASE("lone_wolf on " #__VA_ARGS__ ", expected =" #expected, "[lone_wolf]") { std::vector<unsigned> ns = __VA_ARGS__; test(ns, expected); }

TEST(0, { 0 } )
TEST(0, { 0, 1, 1 })
TEST(0, { 1, 0, 1 })
TEST(0, { 1, 1, 0 })
TEST(1, { 1, 0, 0 })
TEST(1, { 0, 1, 0 })
TEST(1, { 0, 0, 1 })
TEST(5, { 1, 1, 2, 2, 3, 3, 4, 4, 5 })
TEST(5, { 5, 1, 1, 2, 2, 3, 3, 4, 4 })
TEST(5, { 1, 1, 5, 2, 2, 3, 3, 4, 4 })
TEST(5, { 1, 2, 3, 4, 5, 4, 3, 2, 1 })
