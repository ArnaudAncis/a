#ifndef COMPLEX_H
#define COMPLEX_H

// Solution is const-correct, this concept might not have been discussed at the time you make this exercise
// If you haven't seen const-correctness, you don't have to end method signatures with "const"

class complex
{
private:
    double m_re, m_im;

public:
    complex(double m_re = 0, double m_im = 0)
        : m_re(m_re), m_im(m_im) { }

    complex(const complex& c)
        : complex(c.m_re, c.m_im) { }

    double  re() const { return m_re; }
    double& re()       { return m_re; }
    double  im() const { return m_im; }
    double& im()       { return m_im; }

    complex add(const complex&) const;
    complex neg() const;
    complex sub(const complex&) const;
    complex mul(const complex&) const;
    complex reciprocal() const;
    complex div(const complex&) const;

    complex conj() const;
    double abs() const;
    double abs_sqr() const;
};

#endif