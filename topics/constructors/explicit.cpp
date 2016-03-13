class Foo
{
public:
  explicit Foo(int) { }
};

void bar(Foo) { }

bar(5);       // error
bar((Foo) 5); // ok, calls constructor
bar(Foo(5));  // ok, calls constructor
