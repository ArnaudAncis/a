// generate_associative_answerboxes
#include <iostream>

struct Foo {
  Foo() : x(0) { }
  Foo(const Foo& foo) : x(foo.x + 1) { }
  
  int x;
};

void bar(Foo foo1, Foo& foo2) {
  foo2.x += foo1.x;
}

int main() {
  Foo foo1;
  Foo foo2 = foo1;
  Foo foo3;

  std::cout << "A:" << foo1.x << std::endl;
  std::cout << "B:" << foo2.x << std::endl;
  bar(foo1, foo3);
  std::cout << "C:" << foo3.x << std::endl;
}
