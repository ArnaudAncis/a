#include "cache.h"
#include "shared.h"
#include <iostream>
#include <vector>


namespace
{
    void process(std::vector<uint64_t>& ns, unsigned block_size, unsigned reads_per_item)
    {
        uint64_t result = 0;

        if (ns.size() % block_size)
        {
            std::cerr << "invalid block size" << std::endl;
            abort();
        }

        auto block_count = ns.size() / block_size;

        for (unsigned block_index = 0; block_index < block_count; ++block_index)
        {
            unsigned start_i = block_index * block_size;

            for (unsigned k = 0; k != reads_per_item * block_size; ++k)
            {
                unsigned i = k * (k ^ 0x395A13C5);
                i = (k ^ (97 * k)) * i;
                i %= block_size;

                result ^= ns[start_i + i];
            }
        }

        ns[0] = result;
    }

    void test(std::vector<uint64_t>& ns, unsigned size, unsigned repeats_per_block)
    {
        unsigned block_size = 8 * (1 << size);
        auto duration = measure_time([&]() {process(ns, block_size, repeats_per_block);}) / repeats_per_block;

        //std::cout
        //    << "Block size " << block_size * sizeof(uint64_t) << " bytes"
        //    << ", " << repeats_per_block << " repeats" 
        //    << ", " << ns.size() / block_size << " blocks"
        //    << " --> " << duration << "ms per repeat on average"
        //    << std::endl;

        std::cout << size << "/" << duration << std::endl;
    }
}

void test_cache()
{
    std::vector<uint64_t> ns(268435456);
    std::vector<int> sizes = range(1, 20);

    for (auto i : sizes)
    {
        test(ns, i, 1);
    }
    std::cout << std::endl;
    for (auto i : sizes)
    {
        test(ns, i, 2);
    }std::cout << std::endl;

    for (auto i : sizes)
    {
        test(ns, i, 4);
    }
    std::cout << std::endl;
    for (auto i : sizes)
    {
        test(ns, i, 8);
    }
}
