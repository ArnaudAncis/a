#include <iostream>
#include <vector>

void foo(std::vector<int> xs) {
  xs[0]++;
}

void bar(std::vector<int>* xs) {
  (*xs)[0]++;
}

void qux(std::vector<int>& xs) {
  xs[0]++;
}

int main() {
  std::vector<int> xs { 0 };
  std::cout << "A:" << xs[0] << std::endl;
  foo(xs);
  std::cout << "B:" << xs[0] << std::endl;
  bar(&xs);
  std::cout << "C:" << xs[0] << std::endl;
  qux(xs);
  std::cout << "D:" << xs[0] << std::endl;
}
