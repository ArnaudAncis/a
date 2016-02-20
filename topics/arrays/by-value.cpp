#include <iostream>
#include <array>

void foo(std::array<int, 1> xs)
{
    xs[0]++;
}

int main() {
    std::array<int, 1> xs = { 0 };

    foo(xs);

    std::cout << xs[0] << std::endl; `\only<2->{\color{red} 0}`
}
