#include <iostream>

class Foo {
public:
  void bar() { print("nonconst"); }
  void bar() const { print("const"); }
};

int main() {
  Foo* p = new Foo();
  const Foo* q = p;

  p->bar(); `\only<2->{\tt // prints nonconst}`
  q->bar(); `\only<3->{\tt // prints const}`

  delete p;
}
