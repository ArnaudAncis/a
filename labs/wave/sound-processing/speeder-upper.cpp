#include "speeder-upper.h"


namespace
{
    class SpeederUpperFunction : public WaveFunction
    {
    private:
        Wave m_wave;
        double m_factor;

    public:
        SpeederUpperFunction(Wave wave, double factor)
            : m_wave(wave), m_factor(factor) { }

        double length() const override { return m_wave.length() / m_factor; }

        double operator [](double t) const override
        {
            return m_wave[t * m_factor];
        }
    };
}

Wave speed_up(Wave wave, double factor)
{
    return Wave(std::make_shared<SpeederUpperFunction>(wave, factor));
}
