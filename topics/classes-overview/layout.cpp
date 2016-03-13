#include "Foo.h"

Foo::Foo(int size)
  : data( new int[size] )
{
}

Foo::~Foo()
{
  delete[] data;
}

int& Foo::at(int i)
{
  return data[i];
}
