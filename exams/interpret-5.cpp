// generate_string_answerbox
#include <iostream>

struct Foo {
  int x;

  void foo()       { std::cout << "A"; }
  void foo() const { std::cout << "B"; }
};

int main() {
  Foo a;
  const Foo& b = a;
  Foo* const c = &a;

  a.foo();
  b.foo();
  c->foo();
}
