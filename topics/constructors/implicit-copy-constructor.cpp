class Foo
{
  T1 t1;
  T2 t2;
  T3 t3;

public:
  // This is what the generated
  // copy constructor would look like
  Foo(const Foo& foo)
    : t1(foo.t1),
      t2(foo.t2),
      t3(foo.t3) { }
};
