// generate_associative_answerboxes
#include <iostream>

struct Foo {
  Foo() : x(0) { }
  Foo(const Foo& foo) : x(foo.x + 1) { }
  
  int x;
};

Foo bar(Foo foo) {
  foo.x++;
  return foo;
}

int main() {
  Foo foo1;
  Foo foo2 = foo1;

  std::cout << "A:" << foo1.x << std::endl;
  std::cout << "B:" << foo2.x << std::endl;
  Foo foo3 = bar(foo1);
  std::cout << "C:" << foo3.x << std::endl;
}
