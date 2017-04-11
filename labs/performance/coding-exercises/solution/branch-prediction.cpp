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

namespace
{
    void process(std::vector<unsigned>& ns)
    {
        for (auto& n : ns)
        {
            if (n % 2)
            {
                n++;
            }
            else
            {
                n--;
            }
        }
    }
}


void test_branch_prediction(int size)
{
    std::cout << "Generating sequential range" << std::endl;
    auto ns = range<unsigned>(0, size);

    std::cout << "Time for ordered list: " << measure_time([&]() {process(ns);}) << std::endl;

    std::cout << "Generating random range" << std::endl;
    ns = range<unsigned>(0, size);
    std::shuffle(ns.begin(), ns.end(), std::default_random_engine());

    std::cout << "Time for unordered list: " << measure_time([&]() {process(ns);}) << std::endl;
}
