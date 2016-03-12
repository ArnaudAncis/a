#include <iostream>

int main()
{
  Person p("Jan", 20);

  std::cout << p.getName()
            << " is "
            << p.getAge()
            << " years old"
            << std::endl;
}
