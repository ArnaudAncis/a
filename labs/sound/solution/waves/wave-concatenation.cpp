#include "waves/wave-concatenation.h"


namespace
{
    class WaveConcatenationFunction : public WaveFunction
    {
        std::vector<Wave> m_waves;
        double m_length;

    public:
        WaveConcatenationFunction(const std::vector<Wave>& waves) : m_waves(waves), m_length(0)
        {
            for (auto& wave : m_waves)
            {
                m_length += wave.length();
            }
        }

        double length() const override
        {
            return m_length;
        }

        double operator [](double t) const
        {
            unsigned index = 0;

            while (t >= m_waves[index].length())
            {
                t -= m_waves[index].length();
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
