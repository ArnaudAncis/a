#include "bytes-buffer.h"
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

BytesBuffer to_bytes_buffer_8bit(const Stream& stream)
{
    BytesBuffer buffer(stream.size());

    for (unsigned i = 0; i != stream.size(); ++i)
    {
        buffer[i] = (uint8_t)(stream[i] * 127 + 127);
    }

    return buffer;
}

BytesBuffer to_bytes_buffer_16bit(const Stream& stream)
{
    BytesBuffer buffer(stream.size() * 2);

    for (unsigned i = 0; i != stream.size(); ++i)
    {
        auto sample = stream[i];
        int16_t sample_as_signed = (int16_t) (sample * 32767);
        uint16_t& sample_as_unsigned = *reinterpret_cast<uint16_t*>(&sample_as_signed);
        byte lower = sample_as_unsigned & 0x00FF;
        byte upper = sample_as_unsigned >> 8;
        buffer[2 * i] = lower;
        buffer[2 * i + 1] = upper;
    }

    return buffer;
}


int main()
{
    // read_wave_file("e:/temp/input.wav");
    

    //auto riff = find_chunk<RIFF_CHUNK>(buffer.get());
    //auto fmt = find_chunk<FMT_CHUNK>(buffer.get() + 12);
    //auto data = find_chunk<DATA_CHUNK>(buffer.get() + 12);
    //auto n_samples = data->chunk_size;
    //auto samples = reinterpret_cast<const uint8_t*>(data) + 8;


    auto wave = std::make_shared<SineWave>(1, 0.9, 440);
    //auto sped_up = std::make_shared<SpeederUpper>(wave, 1.0);
    auto sampled = std::make_shared<WaveSamplingStream>(wave, 44100);

    // auto stream = from_uint8(samples, n_samples);
    auto output_samples = to_bytes_buffer_8bit(*sampled);


    WAVE_DATA wave_data;
    wave_data.bits_per_sample = 8;
    wave_data.n_channels = 1;
    wave_data.sample_rate = 44100;
    wave_data.bytes = output_samples;

    write_wave_file("e:/temp/output.wav", wave_data);
    // write_wave("e:/temp/output.wav", output_samples.get(), sampled->size());

    std::cout << "Done!" << std::endl;
}
