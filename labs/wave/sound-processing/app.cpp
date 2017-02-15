#include "buffer.h"
#include "wave.h"
#include "sine-wave.h"
#include "wave-addition.h"
#include "wave-sampling-stream.h"
#include "sample-stream.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>


#pragma pack(push, 1)

struct CHUNK
{
    uint32_t chunk_id;
    uint32_t chunk_size;
};

struct RIFF_CHUNK
{
    uint32_t chunk_id;
    uint32_t chunk_size;
    uint32_t format;
};

struct FMT_CHUNK
{
    uint32_t chunk_id;
    uint32_t chunk_size;
    uint16_t audio_format;
    uint16_t channels;
    uint32_t sample_rate;
    uint32_t byte_rate;
    uint16_t block_align;
    uint16_t bits_per_sample;
};

struct DATA_CHUNK
{
    uint32_t chunk_id;
    uint32_t chunk_size;
};

#pragma pack(pop)

template<typename T>
unsigned chunk_id();

template<>
unsigned chunk_id<RIFF_CHUNK>()
{
    return 0x46464952;
}

template<>
unsigned chunk_id<FMT_CHUNK>()
{
    return 0x20746d66;
}

template<>
unsigned chunk_id<DATA_CHUNK>()
{
    return 0x61746164;
}

const RIFF_CHUNK* find_riff_chunk(const uint8_t* buffer)
{
    const RIFF_CHUNK* chunk = reinterpret_cast<const RIFF_CHUNK*>(buffer);

    if (chunk->chunk_id == 0x46464952)
    {
        return chunk;
    }
    else
    {
        return nullptr;
    }
}

template<typename T>
const T* find_chunk(const uint8_t* buffer)
{
    const T* chunk = reinterpret_cast<const T*>(buffer);

    while ( chunk->chunk_id != chunk_id<T>() )
    {
        buffer += 8 + chunk->chunk_size;
        chunk = reinterpret_cast<const T*>(buffer);
    }
    
    return chunk;
}

std::unique_ptr<uint8_t[]> read_file(const std::string& filename)
{
    std::ifstream in(filename, std::ios::binary | std::ios::ate);
    auto size = in.tellg();
    in.seekg(0, std::ios::beg);

    std::unique_ptr<uint8_t[]> buffer(new uint8_t[(unsigned)size]);
    uint8_t* p = buffer.get();
    in.read(reinterpret_cast<char*>(buffer.get()), size);

    return buffer;
}

void write_wave(const std::string& filename, const uint8_t* buffer, unsigned size)
{
    std::ofstream out(filename, std::ios::binary);
    
    RIFF_CHUNK riff{ chunk_id<RIFF_CHUNK>(), 4 + sizeof(FMT_CHUNK) + sizeof(DATA_CHUNK) + size, 0x45564157 };
    out.write(reinterpret_cast<const char*>(&riff), sizeof(RIFF_CHUNK));

    FMT_CHUNK fmt{ chunk_id<FMT_CHUNK>(), sizeof(FMT_CHUNK) - 8, 1, 1, 44100, 44100, 1, 8 };
    out.write(reinterpret_cast<const char*>(&fmt), sizeof(FMT_CHUNK));

    DATA_CHUNK data{ chunk_id<DATA_CHUNK>(), size };
    out.write(reinterpret_cast<const char*>(&data), sizeof(DATA_CHUNK));

    out.write(reinterpret_cast<const char*>(buffer), size);
}




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
    //auto buffer = read_file("e:/temp/input.wav");

    //auto riff = find_chunk<RIFF_CHUNK>(buffer.get());
    //auto fmt = find_chunk<FMT_CHUNK>(buffer.get() + 12);
    //auto data = find_chunk<DATA_CHUNK>(buffer.get() + 12);
    //auto n_samples = data->chunk_size;
    //auto samples = reinterpret_cast<const uint8_t*>(data) + 8;

    auto wave = std::make_shared<SineWave>(1, 0.5, 440);
    auto sped_up = std::make_shared<SpeederUpper>(wave, 1.0);
    auto sampled = std::make_shared<WaveSamplingStream>(sped_up, 44100);

    // auto stream = from_uint8(samples, n_samples);
    auto output_samples = to_uint8(*sampled);

    write_wave("e:/temp/output.wav", output_samples.get(), sampled->size());

    std::cout << "Done!" << std::endl;
}