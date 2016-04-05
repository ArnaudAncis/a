struct A {
  A(int);
};

struct B : public A {
  B() : A(0) { }
};
