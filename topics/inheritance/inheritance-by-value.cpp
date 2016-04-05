class A { };
class B : public A { };

void foo(A);
B b;

// Throws away B-specific members
foo(b);


