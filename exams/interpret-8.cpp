// generate_string_answerbox n=10
#include <iostream>

struct Foo {
  Foo() { std::cout << "FD"; }
  ~Foo() { std::cout << "FX"; }
};

struct Bar : public Foo {
  Bar() { std::cout << "BD"; }
  ~Bar() { std::cout << "BX"; }
};

int main() {
  Bar bar;
}
