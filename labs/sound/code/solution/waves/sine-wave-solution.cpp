#include "solution/waves/sine-wave-solution.h"
#include <math.h>


namespace
{
    class SineWaveFunction : public WaveFunction
    {
    private:
        double m_length;
        double m_amplitude;
        double m_frequency;

    public:
        SineWaveFunction(double length, double amplitude, double frequency)
            : m_length(length), m_amplitude(amplitude), m_frequency(frequency) { }
            
        double length() const override 
        { 
            return m_length;
        }

        double operator [](double t) const override
        {
            return m_amplitude * sin(2 * 3.141592 * m_frequency * t);
        }
    };
}

Wave solution::sine_wave(double length, double amplitude, double frequency)
{
    return Wave(std::make_shared<SineWaveFunction>(length, amplitude, frequency));
}
