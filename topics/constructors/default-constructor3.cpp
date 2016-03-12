#include <iostream>

class Foo {
public:
  Foo() : x(5) { }
  int x;
};

void foo() { return Foo`\only<2->{\color{red}\tt()}`; }

int main() {
  Foo foo = foo();
  std::cout << foo.x << std::endl;
}
