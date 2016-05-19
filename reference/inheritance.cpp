struct Foo : `\textit{access-modifier}` `\textit{supertype}`
{
  // Virtual destructor
  virtual ~Foo() { }

  // Virtual member function
  virtual void f() { ... }

  // Abstract member function
  virtual void g() = 0;

  // Overriding member function
  void h() override { ... }
};
