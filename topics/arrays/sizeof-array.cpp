#include <iostream>

void foo(int xs[5]) {
  std::cout << sizeof(xs) << std::endl; `\only<3->{\color{red} 8}`
}

void bar(int xs[]) {
  std::cout << sizeof(xs) << std::endl; `\only<4->{\color{red} 8}`
}

int main() {
  int xs[] = { 1, 2, 3, 4, 5 };
  std::cout << sizeof(xs) << std::endl; `\only<2->{\color{red} 20}`
  foo(xs);
  bar(xs);
}
