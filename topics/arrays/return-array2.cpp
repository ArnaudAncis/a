#include <iostream>

int* range(int from, int until) {
  int size = until - from + 1;
  int xs[size];
  for (int i = 0; i < size; ++i) {
    xs[i] = from + i;
  }
  return xs;
}

int main() {
  int* xs = range(2, 5);

  for (int x : xs) {
    std::cout << x << std::endl;
  }
}
