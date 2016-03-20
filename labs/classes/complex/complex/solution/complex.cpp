#include "complex.h"
#include <cmath>

complex complex::add(const complex& c) const
{
    return complex(m_re + c.m_re, m_im + c.m_im);
}

complex complex::neg() const
{
    return complex(-m_re, -m_im);
}

complex complex::sub(const complex& c) const
{
    return add(c.neg());
}

complex complex::mul(const complex& other) const
{
    // https://en.wikipedia.org/wiki/Complex_number#Multiplication_and_division
    
    // Introducing aliases to better m_readability
    const double& a = this->m_re;
    const double& b = this->m_im;
    const double& c = other.m_re;
    const double& d = other.m_im;

    return complex(a * c - b * d, b * c + a * d);
}

complex complex::reciprocal() const
{
    // https://en.wikipedia.org/wiki/Complex_number#m_reciprocal

    double denom = abs_sqr();

    return complex(m_re / denom, -m_im / denom);
}

complex complex::div(const complex& c) const
{
    return mul(c.reciprocal());
}

complex complex::conj() const
{
    return complex(m_re, -m_im);
}

double complex::abs() const
{
    return std::sqrt(abs_sqr());
}

double complex::abs_sqr() const
{
    return m_re * m_re + m_im * m_im;
}