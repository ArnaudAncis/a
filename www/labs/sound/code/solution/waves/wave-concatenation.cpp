#include "waves/wave-concatenation.h"


namespace
{
    class WaveConcatenationFunction : public WaveFunction
    {
        std::vector<Wave> m_waves;
        double m_duration;

    public:
        WaveConcatenationFunction(const std::vector<Wave>& waves) : m_waves(waves), m_duration(0)
        {
            for (auto& wave : m_waves)
            {
                m_duration += wave.duration();
            }
        }

        double duration() const override
        {
            return m_duration;
        }

        double operator [](double t) const
        {
            unsigned index = 0;

            while (t >= m_waves[index].duration())
            {
                t -= m_waves[index].duration();
                ++index;
            }

            return m_waves[index][t];
        }
    };
}

Wave concatenate(const std::vector<Wave>& waves)
{
    return Wave(std::make_shared<WaveConcatenationFunction>(waves));
}
