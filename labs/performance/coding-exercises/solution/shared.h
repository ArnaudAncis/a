#ifndef SHARED_H
#define SHARED_H

#include <functional>
#include <algorithm>
#include <vector>
#include <random>

long long measure_time(std::function<void()> function);

template<typename T>
std::vector<T> range(T from, T to)
{
    std::vector<T> result(to - from);

    int index = 0;
    for (T value = from; value != to; ++value)
        result[index++] = value;

    return result;
}

template<typename T>
void shuffle(std::vector<T>& xs)
{
    std::shuffle(xs.begin(), xs.end(), std::default_random_engine());
}

template<typename T>
std::vector<T> create_vector(unsigned size, std::function<T(unsigned)> f)
{
    std::vector<T> result(size);

    for (unsigned i = 0; i != size; ++i)
    {
        result[i] = f(i);
    }

    return result;
}

#endif
