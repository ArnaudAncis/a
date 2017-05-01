#include "waves/zero-wave.h"


namespace
{
    class ZeroWaveFunction : public WaveFunction
    {
        double m_duration;

    public:
        ZeroWaveFunction(double duration) : m_duration(duration) { }

        double duration() const override
        {
            return m_duration;
        }

        double operator [](double t) const override
        {
            return 0;
        }
    };
}

Wave zero_wave(double duration)
{
    return Wave(std::make_shared<ZeroWaveFunction>(duration));
}
