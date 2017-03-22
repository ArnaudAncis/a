#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
    double re, im;

    Complex(double re, double im) : re(re), im(im) { }

};

Complex operator +(const Complex&, const Complex&);
Complex operator +(const Complex&);
Complex operator -(const Complex&, const Complex&);
Complex operator *(const Complex&, const Complex&);
Complex operator /(const Complex&, const Complex&);

#endif
