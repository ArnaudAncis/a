#include "complex.h"
#include <cmath>

complex::complex(double re, double im)
    : m_re(re), m_im(im)
{
    // NOP
}

double& complex::re()
{
    return m_re;
}

double complex::re() const
{
    return m_re;
}

double& complex::im()
{
    return m_im;
}

double complex::im() const
{
    return m_im;
}

complex complex::reciprocal() const
{
    // https://en.wikipedia.org/wiki/Complex_number#m_reciprocal

    double denom = abs_sqr();

    return complex(m_re / denom, -m_im / denom);
}

double complex::abs() const
{
    return std::sqrt(abs_sqr());
}

double complex::abs_sqr() const
{
    return m_re * m_re + m_im * m_im;
}

complex complex::conj() const
{
    return complex(m_re, -m_im);
}

complex& complex::operator=(const complex& c)
{
    m_re = c.m_re;
    m_im = c.m_im;

    return *this;
}

complex operator -(const complex& c)
{
    return complex(-c.re(), -c.im());
}

complex operator +(const complex& c1, const complex& c2)
{
    return complex(c1.re() + c2.re(), c1.im() + c2.im());
}

complex operator -(const complex& c1, const complex& c2)
{
    return c1 + (-c2);
}

complex operator *(const complex& c1, const complex& c2)
{
    double a = c1.re();
    double b = c1.im();
    double c = c2.re();
    double d = c2.im();

    return complex(a * c - b * d, b * c + a * d);
}

complex operator /(const complex& c1, const complex& c2)
{
    return c1 * c2.reciprocal();
}

complex& operator +=(complex& c1, const complex& c2)
{
    return c1 = c1 + c2;
}

complex& operator -=(complex& c1, const complex& c2)
{
    return c1 = c1 - c2;
}

complex& operator *=(complex& c1, const complex& c2)
{
    return c1 = c1 * c2;
}

complex& operator /=(complex& c1, const complex& c2)
{
    return c1 = c1 / c2;
}