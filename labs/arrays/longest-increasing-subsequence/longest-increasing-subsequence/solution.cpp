#include <vector>

bool longest_increasing_subsequence(const std::vector<int>* ns, int* start_index, int* end_index)
{
    if ((*ns).empty())
    {
        return false;
    }
    else
    {
        *start_index = 0;
        *end_index = 0;
        unsigned greatest_length = 0;
        unsigned last_start = 0;

        for (unsigned i = 1; i < (*ns).size(); ++i)
        {
            if ((*ns)[i - 1] <= (*ns)[i])
            {
                unsigned length = i - last_start + 1;

                if (length > greatest_length)
                {
                    *start_index = last_start;
                    *end_index = i;
                    greatest_length = length;
                }
            }
            else
            {
                last_start = i;
            }
        }

        return true;
    }
}


/*

TESTS

*/

#define CATCH_CONFIG_MAIN
#include "Catch.h"

void test_success(const std::vector<int>& ns, int expected_start, int expected_end)
{
    int actual_start, actual_end;
    bool result = longest_increasing_subsequence(&ns, &actual_start, &actual_end);

    REQUIRE(result);
    REQUIRE(actual_start == expected_start);
    REQUIRE(actual_end == expected_end);
}

void test_failure()
{
    std::vector<int> ns;
    int actual_start, actual_end;
    bool result = longest_increasing_subsequence(&ns, &actual_start, &actual_end);

    REQUIRE(!result);
}

#define SUCCESS(expected_start, expected_end, ...) TEST_CASE("longest_increasing_subsequence on " #__VA_ARGS__ ", expected start=" #expected_start ", expected end=" #expected_end, "[longest_increasing_subsequence]") { std::vector<int> ns = __VA_ARGS__; test_success(ns, expected_start, expected_end); }
#define FAILURE TEST_CASE("longest_increasing_subsequence on { } should return false") { test_failure(); }


SUCCESS(0, 0, { 0 })
SUCCESS(0, 1, { 0, 1 })
SUCCESS(0, 2, { 0, 1, 2 })
SUCCESS(0, 3, { 0, 1, 2, 3 })
SUCCESS(0, 3, { 1, 1, 2, 3 })
SUCCESS(1, 3, { 2, 1, 2, 3 })
SUCCESS(5, 8, { 0, 1, 0, 1, 2, 0, 1, 2, 3 })
SUCCESS(0, 3, { 0, 0, 0, 0 })
SUCCESS(0, 3, { 1, 1, 1, 1 })
SUCCESS(0, 3, { 1, 1, 1, 1, 0 })
SUCCESS(0, 3, { 1, 1, 1, 1, 0, 0 })
SUCCESS(0, 3, { 1, 1, 1, 1, 0, 0, 0 })
SUCCESS(0, 3, { 1, 1, 1, 1, 0, 0, 0, 0 })
SUCCESS(4, 8, { 1, 1, 1, 1, 0, 0, 0, 0, 0 })
SUCCESS(0, 0, { 5, 4, 3, 2, 1, 0 })
FAILURE
