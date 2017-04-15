#include "bytes-buffer.h"
#include "wave.h"
#include "sine-wave.h"
#include "wave-addition.h"
#include "wave-sampling-stream.h"
#include "sample-stream.h"
#include "wave-file.h"
#include "double-to-int16-converter.h"
#include "int16-to-double-converter.h"
#include "int16-stream-splitter.h"
#include "int16-stream-builder.h"
#include "interpolator.h"
#include "speeder-upper.h"
#include <iostream>
#include <vector>
#include <memory>
#include <assert.h>


//
//std::shared_ptr<Stream<double>> from_uint8(const uint8_t* buffer, unsigned n_samples)
//{
//    std::vector<double> samples(n_samples);
//
//    for (unsigned i = 0; i != n_samples; ++i)
//    {
//        samples[i] = (buffer[i] - 127.5) / 127.5;
//    }
//
//    return std::make_shared<SampleStream>(samples);
//}
//
//BytesBuffer to_bytes_buffer_8bit(const Stream<double>& stream)
//{
//    BytesBuffer buffer(stream.size());
//
//    for (unsigned i = 0; i != stream.size(); ++i)
//    {
//        auto sample = stream[i];
//        int32_t sample_as_int = (int32_t)(sample * 127 + 127);
//
//        assert(0 <= sample_as_int);
//        assert(sample_as_int <= 255);
//
//        buffer[i] = (uint8_t)(sample_as_int);
//    }
//
//    return buffer;
//}
//
//BytesBuffer to_bytes_buffer_16bit(const Stream<double>& stream)
//{
//    BytesBuffer buffer(stream.size() * 2);
//
//    for (unsigned i = 0; i != stream.size(); ++i)
//    {
//        auto sample = stream[i];
//        int16_t sample_as_signed = (int16_t) (sample * 32767);
//        uint16_t& sample_as_unsigned = *reinterpret_cast<uint16_t*>(&sample_as_signed);
//        byte lower = sample_as_unsigned & 0x00FF;
//        byte upper = sample_as_unsigned >> 8;
//        buffer[2 * i] = lower;
//        buffer[2 * i + 1] = upper;
//    }
//
//    return buffer;
//}


int main()
{
    WAVE_DATA wave_data;
    read_wave_file("e:/temp/wave/input-16bit-44-mono.wav", &wave_data);

    if (wave_data.n_channels != 1 || wave_data.sample_rate != 44100 || wave_data.bits_per_sample != 16)
    {
        std::cerr << "Unsupported format" << std::endl;
        std::cerr << "Channels: " << wave_data.n_channels << std::endl;
        std::cerr << "Sample rate: " << wave_data.sample_rate << std::endl;
        std::cerr << "Bits per sample: " << wave_data.bits_per_sample << std::endl;
        abort();
    }

    auto uint8_input = wave_data.stream;
    auto int16_input = convert_uint8_to_int16_stream(uint8_input);
    auto double_input = convert_int16_to_double_stream(int16_input);
    auto wave = interpolate(double_input, wave_data.sample_rate);

    // auto wave = std::make_shared<SineWave>(1, 0.25, 440);
    
    auto result_wave = speed_up(wave, 1.5);
    auto double_samples = sample_wave(result_wave, 44100);

    // auto stream = from_uint8(samples, n_samples);
    // auto output_samples = to_bytes_buffer_16bit(*sampled);
    auto int16_samples = convert_double_to_int16_stream(double_samples);
    auto output_stream = convert_int16_to_uint8_stream(int16_samples);

    wave_data.bits_per_sample = 16;
    wave_data.n_channels = 1;
    wave_data.sample_rate = 44100;
    wave_data.stream = output_stream;

    write_wave_file("e:/temp/wave/output.wav", wave_data);
    // write_wave("e:/temp/output.wav", output_samples.get(), sampled->size());

    std::cout << "Done!" << std::endl;
}
