int x = 5;

int& foo()
{
  return x;
}

foo() = 6;
