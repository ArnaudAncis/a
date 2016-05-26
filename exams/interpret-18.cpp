// generate_string_answerbox n=10
#include <iostream>

struct Foo {
  int  operator [](int) { std::cout << "A"; return 5; }
  Foo& operator ()()    { std::cout << "B"; return *this; }

  Foo& operator -()     { std::cout << "D"; return *this; }
  Foo& operator -(int)  { std::cout << "E"; return *this; }
};

int main() {
  Foo a;

  std::cout << (-(a())-5)[4];
}
