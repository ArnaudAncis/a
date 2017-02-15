#ifndef SINE_WAVE_H
#define SINE_WAVE_H

#include "wave.h"


class SineWave : public Wave
{
private:
    double m_length;
    double m_amplitude;
    double m_frequency;

public:
    SineWave(double length, double amplitude, double frequency);

    double length() const override;

    double operator [](double t) const override;
};

#endif
