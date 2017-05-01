#include "waves/wave.h"
#include <algorithm>


namespace
{
    class WaveAdditionFunction : public WaveFunction
    {
        Wave m_first;
        Wave m_second;

    public:
        WaveAdditionFunction(Wave first, Wave second)
            : m_first(first), m_second(second) { }

        double duration() const override
        {
            return std::max(m_first.duration(), m_second.duration());
        }

        double operator [](double t) const override
        {
            double a = t < m_first.duration() ? m_first[t] : 0;
            double b = t < m_second.duration() ? m_second[t] : 0;

            return a + b;
        }
    };

    class WaveMultiplicationFunction : public WaveFunction
    {
        Wave m_wave;
        double m_factor;

    public:
        WaveMultiplicationFunction(Wave wave, double factor)
            : m_wave(wave), m_factor(factor) { }

        double duration() const override
        {
            return m_wave.duration();
        }

        double operator [](double t) const override
        {
            return m_wave[t] * m_factor;
        }
    };

    class WaveDelayerFunction : public WaveFunction
    {
        Wave m_wave;
        double m_delay;

    public:
        WaveDelayerFunction(Wave wave, double delay)
            : m_wave(wave), m_delay(delay) { }

        double duration() const override
        {
            return m_wave.duration() + m_delay;
        }

        double operator [](double t) const override
        {
            if (t < m_delay) return 0;
            else return m_wave[t - m_delay];
        }
    };
}

Wave operator +(Wave a, Wave b)
{
    return Wave(std::make_shared<WaveAdditionFunction>(a, b));
}

Wave& operator +=(Wave a, Wave b)
{
    return a = a + b;
}

Wave operator *(Wave wave, double factor)
{
    return Wave(std::make_shared<WaveMultiplicationFunction>(wave, factor));
}

Wave operator *(double factor, Wave wave)
{
    return wave * factor;
}

Wave& operator *=(Wave wave, double factor)
{
    return wave = wave * factor;
}

Wave operator /(Wave wave, double factor)
{
    return wave * (1.0 / factor);
}

Wave& operator /=(Wave wave, double factor)
{
    return wave = wave / factor;
}

Wave operator >>(Wave wave, double delay)
{
    return Wave(std::make_shared<WaveDelayerFunction>(wave, delay));
}

Wave& operator >>=(Wave wave, double delay)
{
    return wave = (wave >> delay);
}