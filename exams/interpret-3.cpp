// generate_associative_answerboxes
#include <iostream>

void foo(int* x, int* y) {
  *x *= *y;
  *y *= *x;
}

int main() {
  int a = 2;
  foo(&a, &a);

  std::cout << "A:" << a << std::endl;
}
