#include "complex.h"


double Complex::abs_sqr() const
{
    return re * re + im * im;
}


Complex Complex::conjugate() const
{
    return Complex(re, -im);
}

Complex operator +(const Complex& a, const Complex& b)
{
    double re = a.re + b.re;
    double im = a.im + b.im;

    return Complex(re, im);
}

Complex operator -(const Complex& a)
{
    double re = -a.re;
    double im = -a.im;

    return Complex(re, im);
}

Complex operator -(const Complex& a, const Complex& b)
{
    return a + (-b);
}

Complex operator *(const Complex& a, const Complex& b)
{
    double re = a.re * b.re - a.im * b.im;
    double im = a.re * b.im + a.im * b.re;

    return Complex(re, im);
}

Complex operator /(const Complex& a, double b)
{
    return Complex(a.re / b, a.im / b);
}

Complex operator /(const Complex& a, const Complex& b)
{
    return (a * b.conjugate()) / b.abs_sqr();
}

Complex& operator +=(Complex& a, const Complex& b)
{
    return (a = a + b);
}

Complex& operator -=(Complex& a, const Complex& b)
{
    return (a = a - b);
}

Complex& operator *=(Complex& a, const Complex& b)
{
    return (a = a * b);
}

Complex& operator /=(Complex& a, const Complex& b)
{
    return (a = a / b);
}

bool operator ==(const Complex& a, const Complex& b)
{
    return a.re == b.re && a.im == b.im;
}

bool operator !=(const Complex& a, const Complex& b)
{
    return !(a == b);
}