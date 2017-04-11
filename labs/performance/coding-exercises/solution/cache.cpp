#include "cache.h"
#include "shared.h"
#include <iostream>
#include <vector>


namespace
{
    void process(std::vector<uint64_t>& ns, unsigned block_size, unsigned repeats_per_block, const std::vector<unsigned>& indices)
    {
        if (ns.size() % block_size)
        {
            std::cerr << "invalid block size" << std::endl;
            abort();
        }

        auto block_count = ns.size() / block_size;

        for (unsigned block_index = 0; block_index < block_count; ++block_index)
        {
            unsigned start_i = block_index * block_size;

            for (unsigned k = 0; k != repeats_per_block; ++k)
            {
                for (auto i : indices)
                {
                    ns[start_i + i]++;
                }
            }
        }
    }

    void test(std::vector<uint64_t>& ns, unsigned block_size, unsigned repeats_per_block)
    {
        auto indices = range<unsigned>(0, block_size);
        shuffle(indices);

        std::cout
            << "Block size " << block_size * sizeof(uint64_t) << " bytes"
            << ", repeat " << repeats_per_block
            << ", " << ns.size() / block_size << " blocks"
            << " --> " << measure_time([&]() {process(ns, block_size, repeats_per_block, indices);})
            << std::endl;
    }
}

void test_cache()
{
    std::vector<uint64_t> ns(268435456);


    for (unsigned i = 0; i <= 25; ++i)
    {
        unsigned block_size = 8 * (1 << i);

        test(ns, block_size, 4);
    }
}
