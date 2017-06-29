// generate_string_answerbox n=24
#include <iostream>

struct Foo {
  Foo()           { std::cout << "FD"; }
  Foo(const Foo&) { std::cout << "FC"; }
  ~Foo()          { std::cout << "FX"; }
};

struct Bar : public Foo {
  Bar()                          { std::cout << "BD"; }
  Bar(const Bar& bar) : Foo(bar) { std::cout << "BC"; }
  ~Bar()                         { std::cout << "BX"; }
};

void qux(Foo foo) { }

int main() {
  Bar bar;

  qux(bar);
}
