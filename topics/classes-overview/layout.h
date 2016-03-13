#ifndef FOO_H
#define FOO_H

class Foo
{
private:
  int* data;

public:
  Foo(int);
  ~Foo();

  int& at(int i);
};

#endif