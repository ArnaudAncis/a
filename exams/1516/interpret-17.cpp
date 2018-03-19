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

int main() {
  Foo a;
  Foo b = a;
  Foo& c = a;

  c = b;
}
