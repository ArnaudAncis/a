#include <iostream>

int main()
{
  std::cout << sizeof(int) << std::endl; // 4
  std::cout << sizeof(int*) << std::endl; // 8

  bool x;
  std::cout << sizeof(x) << std::endl; // 1
  std::cout << sizeof(&x) << std::endl; // 8
}
