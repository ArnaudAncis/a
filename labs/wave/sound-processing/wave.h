#ifndef WAVE_H
#define WAVE_H

class Wave
{
public:
    virtual double length() const = 0;
    virtual double operator [](double) const = 0;
};

#endif
