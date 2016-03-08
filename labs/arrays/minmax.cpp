#include <iostream>
#include <array>
#include <vector>
#include <limits>

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

void minmax(int* ns, int length, int* min, int* max)
{
    *min = std::numeric_limits<int>::max();
    *max = std::numeric_limits<int>::min();

    for (int i = 0; i != length; ++i)
    {
        update_minmax(min, max, ns[i]);
    }
}

void minmax(std::vector<int>* ns, int* min, int* max)
{
    *min = std::numeric_limits<int>::max();
    *max = std::numeric_limits<int>::min();

    for (int n : *ns)
    {
        update_minmax(min, max, n);
    }
}

template<unsigned N>
void minmax(std::array<int, N>* ns, int* min, int* max)
{
    *min = std::numeric_limits<int>::max();
    *max = std::numeric_limits<int>::min();

    for (int n : *ns)
    {
        update_minmax(min, max, n);
    }
}

int main()
{
    int min, max;

    {
        int ns[] = { 5, 1, 8, 2, 9, 4, 0, 7, 6 };
        minmax(ns, sizeof(ns) / sizeof(int), &min, &max);
        std::cout << min << " " << max << std::endl;
    }

    {
        std::vector<int> ns = { 5, 1, 8, 2, 9, 4, 0, 7, 6 };
        minmax(&ns, &min, &max);
        std::cout << min << " " << max << std::endl;
    }

    {
        std::array<int, 9> ns = { 5, 1, 8, 2, 9, 4, 0, 7, 6 };
        minmax(&ns, &min, &max);
        std::cout << min << " " << max << std::endl;
    }
}
