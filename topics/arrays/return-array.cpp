#include <iostream>

int[] range(int from, int until) {
    int xs[until - from + 1];
    for (int i = 0; i <= until; ++i) {
        xs[i] = from + i;
    }
    return xs;
}

int main() {
    int xs[] = create_array();

    for (int x : xs) {
        std::cout << x << std::endl;
    }
}
