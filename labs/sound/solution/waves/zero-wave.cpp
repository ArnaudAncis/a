#include "waves/zero-wave.h"


namespace
{
    class ZeroWaveFunction : public WaveFunction
    {
        double m_length;

    public:
        ZeroWaveFunction(double length) : m_length(length) { }

        double length() const override
        {
            return m_length;
        }

        double operator [](double t) const override
        {
            return 0;
        }
    };
}

Wave zero_wave(double length)
{
    return Wave(std::make_shared<ZeroWaveFunction>(length));
}
