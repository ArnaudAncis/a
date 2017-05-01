#ifndef TEST_BUILD
#include "streams/bytes-buffer.h"
#include "streams/normaliser.h"
#include "streams/converters/conversions.h"
#include "streams/multiplexer.h"
#include "waves/waves.h"
#include "wave-file.h"
#include <iostream>
#include <vector>
#include <memory>
#include <assert.h>


//void melody_mono()
//{
//    WAVE_DATA wave_data;
//
//    auto wf = wave_factory(square_wave);
//    auto result_wave = treble(wf) + bass(wf);
//
//    auto double_samples = normalise(sample_wave(result_wave, 44100));
//    auto int16_samples = convert_double_to_int16_stream(double_samples);
//    auto output_stream = convert_int16_to_uint8_stream(int16_samples);
//
//    wave_data.bits_per_sample = 16;
//    wave_data.n_channels = 1;
//    wave_data.sample_rate = 44100;
//    wave_data.stream = output_stream;
//
//    write_wave_file("e:/temp/wave/output.wav", wave_data);
//}
//
//void melody_stereo()
//{
//    WAVE_DATA wave_data;
//
//    auto wf = wave_factory(sine_wave);
//    auto result_left = treble(wf);
//    auto result_right = bass(wf);
//
//    auto double_samples_left = normalise(sample_wave(result_left, 44100));
//    auto double_samples_right = normalise(sample_wave(result_right, 44100));
//
//    auto int16_samples_left = convert_double_to_int16_stream(double_samples_left);
//    auto int16_samples_right = convert_double_to_int16_stream(double_samples_right);
//
//    auto stereo_samples = multiplex(int16_samples_left, int16_samples_right);
//    auto output_stream = convert_int16_to_uint8_stream(stereo_samples);
//
//    wave_data.bits_per_sample = 16;
//    wave_data.n_channels = 2;
//    wave_data.sample_rate = 44100;
//    wave_data.stream = output_stream;
//
//    write_wave_file("e:/temp/wave/output.wav", wave_data);
//}
//
//void convert_8bit_file()
//{
//    WAVE_DATA wave_data;
//
//    read_wave_file("e:/temp/wave/input-8bit-44-mono.wav", &wave_data);
//
//    if (wave_data.n_channels != 1 || wave_data.sample_rate != 44100 || wave_data.bits_per_sample != 8)
//    {
//        std::cerr << "Unsupported format" << std::endl;
//        std::cerr << "Channels: " << wave_data.n_channels << std::endl;
//        std::cerr << "Sample rate: " << wave_data.sample_rate << std::endl;
//        std::cerr << "Bits per sample: " << wave_data.bits_per_sample << std::endl;
//        abort();
//    }
//
//    auto uint8_input = wave_data.stream;
//    auto double_input = convert_uint8_to_double_stream(uint8_input);
//    auto wave = interpolate(double_input, wave_data.sample_rate);
//    auto result_wave = wave;
//
//    auto double_samples = normalise(sample_wave(result_wave, 44100));
//    auto int16_samples = convert_double_to_int16_stream(double_samples);
//    auto output_stream = convert_int16_to_uint8_stream(int16_samples);
//
//    wave_data.bits_per_sample = 16;
//    wave_data.n_channels = 1;
//    wave_data.sample_rate = 44100;
//    wave_data.stream = output_stream;
//
//    write_wave_file("e:/temp/wave/output.wav", wave_data);
//}
//
//void convert_16bit_file()
//{
//    WAVE_DATA wave_data;
//
//    read_wave_file("e:/temp/wave/input-16bit-44-mono.wav", &wave_data);
//
//    if (wave_data.n_channels != 1 || wave_data.sample_rate != 44100 || wave_data.bits_per_sample != 16)
//    {
//        std::cerr << "Unsupported format" << std::endl;
//        std::cerr << "Channels: " << wave_data.n_channels << std::endl;
//        std::cerr << "Sample rate: " << wave_data.sample_rate << std::endl;
//        std::cerr << "Bits per sample: " << wave_data.bits_per_sample << std::endl;
//        abort();
//    }
//
//    auto uint8_input = wave_data.stream;
//    auto int16_input = convert_uint8_to_int16_stream(uint8_input);
//    auto double_input = convert_int16_to_double_stream(int16_input);
//    auto wave = interpolate(double_input, wave_data.sample_rate);
//    auto result_wave = wave;
//
//    auto double_samples = normalise(sample_wave(result_wave, 44100));
//    auto int16_samples = convert_double_to_int16_stream(double_samples);
//    auto output_stream = convert_int16_to_uint8_stream(int16_samples);
//
//    wave_data.bits_per_sample = 16;
//    wave_data.n_channels = 1;
//    wave_data.sample_rate = 44100;
//    wave_data.stream = output_stream;
//
//    write_wave_file("e:/temp/wave/output.wav", wave_data);
//}

int main()
{
    // melody_mono();
    // melody_stereo();
    // convert_16bit_file();

    std::cout << "Done!" << std::endl;
}
#endif
