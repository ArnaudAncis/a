void foo(int& x)
{
  ++x;
}

int x = 3;
foo(x);
std::cout << x << std::endl; `\visible<2->{\tt 4}`
