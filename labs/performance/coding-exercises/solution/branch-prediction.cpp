#include "branch-prediction.h"
#include "shared.h"
#include <iostream>
#include <memory>
#include <chrono>
#include <cstdint>
#include <random>
#include <functional>
#include <vector>
#include <algorithm>
#include <functional>


namespace
{
    uint64_t process(uint64_t max, unsigned mask)
    {
        uint64_t result = 0;

        for (uint64_t i = 0; i != max; ++i)
        {
            if (i & mask)
            {
                result *= 2;
            }
            else
            {
                result++;
            }
        }

        return result;
    }

    void test(uint64_t max, unsigned mask)
    {
        uint64_t result;

        auto duration = measure_time([max, mask, &result]() {
            result = process(max, mask);
        });

        std::cout << "Masking with " << mask << " up to " << max << " --> " << duration << " [" << result << "]" << std::endl;
    }
}


void test_branch_prediction(uint64_t size)
{
    //test(std::vector<unsigned> { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, size);
    //test(std::vector<unsigned> { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, size);
    //test(std::vector<unsigned> { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 }, size);
    //test(std::vector<unsigned> { 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0 }, size);
    //test(std::vector<unsigned> { 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0 }, size);
    //test(std::vector<unsigned> { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1 }, size);
    test(size, 0);
    test(size, -1);

    for (unsigned i = 0; i != 16; ++i)
    {
        test(size, i);
    }
    for (unsigned i = 0; i != 16; ++i)
    {
        test(size, i);
    }
}