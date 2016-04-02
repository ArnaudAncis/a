#ifndef COMPLEX_H
#define COMPLEX_H

class complex
{
private:
    double m_re, m_im;

public:
    complex(double = 0, double = 0);
    complex(const complex&) = default;

    double& re();
    double re() const;

    double& im();
    double im() const;

    complex reciprocal() const;
    double abs() const;
    double abs_sqr() const;
    complex conj() const;

    complex& operator =(const complex&);
};

complex operator -(const complex&);

complex operator +(const complex&, const complex&);
complex operator -(const complex&, const complex&);
complex operator *(const complex&, const complex&);
complex operator /(const complex&, const complex&);

complex& operator +=(complex&, const complex&);
complex& operator -=(complex&, const complex&);
complex& operator *=(complex&, const complex&);
complex& operator /=(complex&, const complex&);

#endif