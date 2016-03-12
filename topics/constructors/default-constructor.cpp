#include <iostream>

class Foo {
public:
  Foo() : x(5) { }
  int x;
};

int main() {
  Foo foo();

  std::cout << foo.x << std::endl;
}
