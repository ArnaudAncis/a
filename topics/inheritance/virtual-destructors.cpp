class A { };

class B1 : public A {
  int* data;
public:
  ~B1() { delete[] data; }
};

class B2 : public A {
public:
  ~B2() {  }
};

void destroy(A* a) {
  delete a; // Which destructor?
}
