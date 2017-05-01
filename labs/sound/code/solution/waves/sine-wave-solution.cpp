#include "solution/waves/sine-wave-solution.h"
#include <math.h>


namespace
{
    class SineWaveFunction : public WaveFunction
    {
    private:
        double m_duration;
        double m_amplitude;
        double m_frequency;

    public:
        SineWaveFunction(double duration, double amplitude, double frequency)
            : m_duration(duration), m_amplitude(amplitude), m_frequency(frequency) { }
            
        double duration() const override 
        { 
            return m_duration;
        }

        double operator [](double t) const override
        {
            return m_amplitude * sin(2 * 3.141592 * m_frequency * t);
        }
    };
}

Wave solution::sine_wave(double duration, double amplitude, double frequency)
{
    return Wave(std::make_shared<SineWaveFunction>(duration, amplitude, frequency));
}
