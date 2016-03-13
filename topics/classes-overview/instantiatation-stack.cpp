#include <iostream>

int main()
{
  Person p("Jan", 20);
  Person q; // Default constructor

  std::cout << p.getName()
            << " is "
            << p.getAge()
            << " years old"
            << std::endl;
}
