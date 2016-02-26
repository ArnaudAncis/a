#include <iostream>

int* range(int from, int until, int* size) {
  *size = until - from + 1;
  int* xs = new int[*size];
  for (int i = 0; i < *size; ++i)
    xs[i] = from + i;
  return xs;
}

int main() {
  int size;
  int* xs = range(2, 5, &size);
  for (int i = 0; i != size; ++i)
    std::cout << xs[i] << std::endl;
  delete[] xs;
}
