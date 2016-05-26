// generate_string_answerbox n=10
#include <iostream>

struct Foo {
  Foo()           { std::cout << "D"; }
  Foo(const Foo&) { std::cout << "C"; }
  ~Foo()          { std::cout << "X"; }

  Foo& operator =(const Foo&) {
    std::cout << "=";
    return *this;
  }
};

Foo bar()
{
  return Foo();
}

int main() {
  Foo a = bar();
  Foo b = a;
  Foo c;

  c = bar();
}
