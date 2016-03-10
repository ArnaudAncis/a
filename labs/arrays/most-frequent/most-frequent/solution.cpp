#include <vector>

void update_minmax(int* min, int* max, int n)
{
    if (n < *min)
    {
        *min = n;
    }

    if (n > *max)
    {
        *max = n;
    }
}

void minmax(const std::vector<int>* ns, int* min, int* max)
{
    *min = std::numeric_limits<int>::max();
    *max = std::numeric_limits<int>::min();

    for (int n : *ns)
    {
        update_minmax(min, max, n);
    }
}

int* create_zero_array(int length)
{
    int* ns = new int[length];

    for (int i = 0; i != length; ++i)
    {
        ns[i] = 0;
    }

    return ns;
}

int most_frequent(const std::vector<int>* ns)
{
    if ((*ns).empty())
    {
        // Return -1 when ns is empty
        return -1;
    }
    else
    {
        // Find min and max values
        int min, max;
        minmax(ns, &min, &max);

        // The array frequencies will contain the frequency of each n of ns
        int* frequencies = create_zero_array(max - min + 1);

        // Count each n of ns
        for (int n : *ns)
        {
            frequencies[n - min]++;
        }

        // Find the n of ns with the greatest frequency
        int result = (*ns)[0];

        for (int n : *ns)
        {
            if (frequencies[n - min] > frequencies[result - min])
            {
                result = n;
            }
        }

        delete[] frequencies;

        return result;
    }
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