#ifndef MINMAX_H
#define MINMAX_H

#include <array>
#include <vector>

void update_minmax(int* min, int* max, int n);
void minmax(const int* ns, int length, int* min, int* max);
void minmax(const std::vector<int>* ns, int* min, int* max);

template<unsigned N>
void minmax(const std::array<int, N>* ns, int* min, int* max)
{
    *min = std::numeric_limits<int>::max();
    *max = std::numeric_limits<int>::min();

    for (int n : *ns)
    {
        update_minmax(min, max, n);
    }
}

#endif