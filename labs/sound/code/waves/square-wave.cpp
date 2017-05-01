#include "waves/square-wave.h"
#include <cmath>


namespace
{
    class SquareWaveFunction : public WaveFunction
    {
    private:
        double m_duration;
        double m_amplitude;
        double m_frequency;

    public:
        SquareWaveFunction(double duration, double amplitude, double frequency)
            : m_duration(duration), m_amplitude(amplitude), m_frequency(frequency) { }

        double duration() const override
        {
            return m_duration;
        }

        double operator [](double t) const override
        {
            auto m = fmod(t * m_frequency, 1.0);

            if (m < 0.5)
            {
                return m_amplitude;
            }
            else
            {
                return -m_amplitude;
            }
        }
    };
}

Wave square_wave(double length, double amplitude, double frequency)
{
    return Wave(std::make_shared<SquareWaveFunction>(length, amplitude, frequency));
}
