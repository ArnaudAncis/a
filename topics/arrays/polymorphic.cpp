#include <array>

template<unsigned N>
int sum(std::array<int, N>* xs) {
    int total = 0;

    for (int x : *xs) {
        total += x;
    }

    return total;
}
