#define WIN32_MEAN_AND_LEAN
#include <Windows.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <functional>


bool is_prime1(unsigned n)
{
    for (unsigned i = 2; i < n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return n > 1;
}

bool is_prime2(unsigned n)
{
    for (unsigned i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return n > 1;
}

bool is_prime3(unsigned n)
{
    unsigned imax = (unsigned)sqrt(n);

    for (unsigned i = 2; i <= imax; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return n > 1;
}


void check(std::vector<std::function<bool(unsigned)>>& functions)
{
    for (unsigned i = 0; i != 100; ++i)
    {
        unsigned count = 0;

        for (auto& is_prime : functions)
        {
            if (is_prime(i))
            {
                count++;
            }
        }

        if (count != 0 && count != functions.size())
        {
            std::cerr << "Error for i=" << i << std::endl;

            for (auto is_prime : functions)
            {
                std::wcout << is_prime(i);
            }

            std::cout << std::endl;
        }
    }
}

void measure(std::vector<std::function<bool(unsigned)>>& functions)
{
    __int64 before, after, frequency;
    QueryPerformanceFrequency((LARGE_INTEGER*) &frequency);

    for (auto& is_prime : functions)
    {
        QueryPerformanceCounter((LARGE_INTEGER*)&before);

        unsigned count = 0;

        for (unsigned i = 0; i != 200000; ++i)
        {
            if (is_prime(i))
            {
                ++count;
            }
        }

        QueryPerformanceCounter((LARGE_INTEGER*)&after);
        double time = double(after - before) / frequency;

        std::cout << count << " " << time << std::endl;
    }
}

int main()
{
    std::vector<std::function<bool(unsigned)>> functions;

    functions.push_back(is_prime1);
    functions.push_back(is_prime2);
    functions.push_back(is_prime3);

    measure(functions);
}