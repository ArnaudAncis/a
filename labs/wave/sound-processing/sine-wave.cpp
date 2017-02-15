#include "sine-wave.h"
#include <math.h>


SineWave::SineWave(double length, double amplitude, double frequency)
    : m_length(length), m_amplitude(amplitude), m_frequency(frequency) { }

double SineWave::length() const
{
    return m_length; 
}

double SineWave::operator [](double t) const
{
    return m_amplitude * sin(2 * 3.141592 * m_frequency * t);
}
