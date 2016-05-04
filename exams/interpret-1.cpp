#include <iostream>

void foo(int x) {
  x++;
}

void bar(int* x) {
  (*x)++;
}

void qux(int& x) {
  x++;
}

int main() {
  int a = 0;
  std::cout << "A:" << a << std::endl;
  foo(a);
  std::cout << "B:" << a << std::endl;
  bar(&a);
  std::cout << "C:" << a << std::endl;
  qux(a);
  std::cout << "D:" << a << std::endl;
}
