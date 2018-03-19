#ifdef TEST_BUILD

#include "tests/testlib.h"
#include "Catch.h"

namespace
{
    class ConstantWaveFunction : public WaveFunction
    {
        double m_duration;
        double m_constant;

    public:
        ConstantWaveFunction(double duration, double constant) : m_duration(duration), m_constant(constant) { }

        double duration() const override
        {
            return m_duration;
        }

        double operator [](double t) const override
        {
            return m_constant;
        }
    };    

    class LinearWaveFunction : public WaveFunction
    {
        double m_duration;
        double m_m, m_q;

    public:
        LinearWaveFunction(double duration, double m, double q) : m_duration(duration), m_m(m), m_q(q) { }

        double duration() const override
        {
            return m_duration;
        }

        double operator [](double t) const override
        {
            return m_m * t + m_q;
        }
    };
}

void check_equal_waves(Wave a, Wave b, double dt)
{
    REQUIRE(a.duration() == Approx(b.duration()));
    
    for (double t = 0; t < a.duration(); t += dt)
    {
        CHECK(a[t] == Approx(b[t]));
    }
}

Wave constant_wave(double duration, double constant)
{
    return Wave(std::make_shared<ConstantWaveFunction>(duration, constant));
}

Wave linear_wave(double duration, double m, double q)
{
    return Wave(std::make_shared<LinearWaveFunction>(duration, m, q));
}

#endif
