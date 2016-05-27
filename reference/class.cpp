class Foo
{
  // Private members
  int x;
  
public:
  Foo() : x(0) { ... }

  // Copy constructor
  Foo(const Foo& foo) : x(foo.x) { ... }

  // Move constructor
  Foo(Foo&& foo) : x(foo.x)  { ... }

  // Destructor
  ~Foo() { ... }

  // Constant member function
  void f() const { ... }

  // Friend function
  friend int bar();

protected:
  ...
};
