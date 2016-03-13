#include <iostream>

class Foo {
public:
  Foo() : x(5) { }
  int x;
};

Foo foo() { return Foo`\only<2->{\color{red}\tt()}`; }

int main() {
  Foo f = foo();
  std::cout << f.x << std::endl;
}
