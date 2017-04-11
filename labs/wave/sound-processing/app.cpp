#include "buffer.h"
#include "wave.h"
#include "sine-wave.h"
#include "wave-addition.h"
#include "wave-sampling-stream.h"
#include "sample-stream.h"
#include "wave-file.h"
#include <iostream>
#include <vector>
#include <memory>







class SpeederUpper : public Wave
{
private:
    std::shared_ptr<Wave> m_wave;
    double m_factor;

public:
    SpeederUpper(std::shared_ptr<Wave> wave, double factor)
        : m_wave(wave), m_factor(factor) { }

    double length() const override { return m_wave->length() / m_factor; }

    double operator [](double t) const override
    {
        return (*m_wave)[t * m_factor];
    }
};

std::shared_ptr<Stream> from_uint8(const uint8_t* buffer, unsigned n_samples)
{
    std::vector<double> samples(n_samples);

    for (unsigned i = 0; i != n_samples; ++i)
    {
        samples[i] = (buffer[i] - 127.5) / 127.5;
    }

    return std::make_shared<SampleStream>(samples);
}

std::unique_ptr<uint8_t[]> to_uint8(const Stream& stream)
{
    std::unique_ptr<uint8_t[]> p(new uint8_t[stream.size()]);

    for (unsigned i = 0; i != stream.size(); ++i)
    {
        p[i] = (uint8_t)(stream[i] * 127.5 + 127.5);
    }

    return p;
}



int main()
{
    read_wave_file("e:/temp/input.wav");
    

    //auto riff = find_chunk<RIFF_CHUNK>(buffer.get());
    //auto fmt = find_chunk<FMT_CHUNK>(buffer.get() + 12);
    //auto data = find_chunk<DATA_CHUNK>(buffer.get() + 12);
    //auto n_samples = data->chunk_size;
    //auto samples = reinterpret_cast<const uint8_t*>(data) + 8;




    //auto wave = std::make_shared<SineWave>(1, 0.5, 440);
    //auto sped_up = std::make_shared<SpeederUpper>(wave, 1.0);
    //auto sampled = std::make_shared<WaveSamplingStream>(sped_up, 44100);

    //// auto stream = from_uint8(samples, n_samples);
    //auto output_samples = to_uint8(*sampled);

    //write_wave("e:/temp/output.wav", output_samples.get(), sampled->size());

    //std::cout << "Done!" << std::endl;
}