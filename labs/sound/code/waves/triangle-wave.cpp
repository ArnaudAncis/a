#include "waves/triangle-wave.h"
#include <assert.h>
#include <cmath>


namespace
{
    class TriangleWaveFunction : public WaveFunction
    {
    private:
        double m_duration;
        double m_amplitude;
        double m_period;

    public:
        TriangleWaveFunction(double duration, double amplitude, double frequency)
            : m_duration(duration), m_amplitude(amplitude), m_period(1/frequency) { }

        double duration() const override
        {
            return m_duration;
        }

        double operator [](double t) const override
        {
            t = fmod(t, m_period) / m_period;

            assert(0 <= t);
            assert(t <= 1);

            if (t < 0.25)
            {
                return (t / 0.25) * m_amplitude;
            }
            else if (t < 0.75)
            {
                t -= 0.25;

                return (1 - 4 * t) * m_amplitude;
            }
            else
            {
                t -= 0.75;
                t *= 4;

                return (t - 1) * m_amplitude;
            }
        }
    };
}

Wave triangle_wave(double length, double amplitude, double frequency)
{
    return Wave(std::make_shared<TriangleWaveFunction>(length, amplitude, frequency));
}
