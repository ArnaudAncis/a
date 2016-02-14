#include <iostream>

unsigned next_unsigned();
bool is_prime(unsigned);
bool is_divisible_by(unsigned, unsigned);
unsigned sqr(unsigned);

int main()
{
    std::cout << "Enter a value: ";
    unsigned n = next_unsigned();
    unsigned k = 1;

    while ( n )
    {
      ++k;
      if ( is_prime(k) ) n--;
    }
    
    std::cout << k << std::endl;
}

unsigned next_unsigned()
{
    unsigned x;
    std::cin >> x;
    return x;
}

bool is_prime(unsigned n)
{
    if (n < 2)
    {
        return false;
    }
    else
    {
        unsigned k = 2;

        while (sqr(k) <= n)
        {
            if (is_divisible_by(n, k))
            {
                return false;
            }

            ++k;
        }

        return true;
    }
}

bool is_divisible_by(unsigned a, unsigned b)
{
    return b != 0 ? a % b == 0 : false;
}

unsigned sqr(unsigned x)
{
    return x * x;
}
