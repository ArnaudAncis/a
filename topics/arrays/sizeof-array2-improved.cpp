#include <iostream>

void foo(int* xs) {
  std::cout << sizeof(xs) << std::endl;
}

void bar(int* xs) {
  std::cout << sizeof(xs) << std::endl;
}

int main() {
  int xs[] = { 1, 2, 3, 4, 5 };
  std::cout << sizeof(xs) << std::endl;
  foo(xs);
  bar(xs);
}
