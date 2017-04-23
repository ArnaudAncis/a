#include "solution/waves/square-wave-solution.h"
#include <cmath>


namespace
{
    class SquareWaveFunction : public WaveFunction
    {
    private:
        double m_length;
        double m_amplitude;
        double m_frequency;

    public:
        SquareWaveFunction(double length, double amplitude, double frequency)
            : m_length(length), m_amplitude(amplitude), m_frequency(frequency) { }

        double length() const override
        {
            return m_length;
        }

        double operator [](double t) const override
        {
            auto m = fmod(t * m_frequency, 1.0);

            if (m < 0.5)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    };
}

Wave solution::square_wave(double length, double amplitude, double frequency)
{
    return Wave(std::make_shared<SquareWaveFunction>(length, amplitude, frequency));
}
