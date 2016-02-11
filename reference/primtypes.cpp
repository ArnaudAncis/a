#include <iostream>
#include <limits>

#define SHOW_RANGE(T) \
  std::cout << #T << ": " << range<T>() << std::endl

template<typename T>
class range { };

template<typename T>
std::ostream& operator <<(std::ostream& out, range<T>)
{
    return out << std::numeric_limits<T>::min()
               << " to "
               << std::numeric_limits<T>::max();
}

std::ostream& operator <<(std::ostream& out, range<char>) 
{
    return out << int(std::numeric_limits<char>::min())
               << " to "
               << int(std::numeric_limits<char>::max());
}

std::ostream& operator <<(std::ostream& out, range<unsigned char>)
{
    return out << int(std::numeric_limits<unsigned char>::min())
               << " to "
               << int(std::numeric_limits<unsigned char>::max());
}

int main()
{
    SHOW_RANGE(char);
    SHOW_RANGE(short);
    SHOW_RANGE(int);
    SHOW_RANGE(long);
    SHOW_RANGE(long long);

    SHOW_RANGE(unsigned char);
    SHOW_RANGE(unsigned short);
    SHOW_RANGE(unsigned int);
    SHOW_RANGE(unsigned long);
    SHOW_RANGE(unsigned long long);

    SHOW_RANGE(float);
    SHOW_RANGE(double);
}
