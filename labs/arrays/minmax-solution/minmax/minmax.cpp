#include "minmax.h"
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

void minmax(const int* ns, int length, int* min, int* max)
{
    *min = std::numeric_limits<int>::max();
    *max = std::numeric_limits<int>::min();

    for (int i = 0; i != length; ++i)
    {
        update_minmax(min, max, ns[i]);
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
