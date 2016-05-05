// generate_string_answerbox n=10
#include <iostream>

struct Foo {
  Foo()           { std::cout << "D"; }
  Foo(const Foo&) { std::cout << "C"; }
  ~Foo()          { std::cout << "X"; }
};

void bar(Foo& foo) { }

int main() {
  std::cout << "1";
  Foo foo;
  std::cout << "2";
  bar(foo);
  std::cout << "3";
}
