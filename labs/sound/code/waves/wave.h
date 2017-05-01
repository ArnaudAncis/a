#ifndef WAVE_H
#define WAVE_H

#include <memory>


class WaveFunction
{
public:
    virtual double duration() const = 0;
    virtual double operator [](double) const = 0;
};

class Wave
{
    std::shared_ptr<WaveFunction> m_function;
    
public:
    Wave(std::shared_ptr<WaveFunction> function) : m_function(function) { }

    double duration() const { return m_function->duration(); }
    double operator [](double t) const { return (*m_function)[t]; }
};

Wave operator +(Wave, Wave);
Wave& operator +=(Wave, Wave);

Wave operator *(Wave, double);
Wave operator *(double, Wave);
Wave& operator *=(Wave, double);

Wave operator /(Wave, double);
Wave& operator /=(Wave, double);

Wave operator >>(Wave, double);
Wave& operator >>=(Wave, double);

#endif
