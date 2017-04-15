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
#include "zero-wave.h"
#include "note.h"
#include "wave-concatenation.h"
#include <iostream>
#include <vector>
#include <memory>
#include <assert.h>


class Composer
{
    std::vector<Wave> m_waves;
    double m_beat_duration;
    int m_octave;
    double m_volume;

public:
    Composer(double tempo) : m_beat_duration(60.0 / tempo), m_octave(4), m_volume(0.5) { }

    Composer& rest(double beats)
    {
        m_waves.push_back(zero_wave(beats * m_beat_duration));

        return *this;
    }

    Composer& add(Note note, double beats)
    {
        auto wave = sine_wave(beats * m_beat_duration, m_volume, note.frequency);
        m_waves.push_back(wave);

        return *this;
    }

    Composer& octave(int octave)
    {
        m_octave = octave;

        return *this;
    }

    Composer& volume(double volume)
    {
        m_volume = volume;
        
        return *this;
    }

    Composer& r4() { return rest(1); }
    Composer& r8() { return rest(0.5); }
    Composer& r16() { return rest(0.25); }

    Composer& a4(int delta = 0) { return add(notes::a(m_octave + delta), 1); }
    Composer& b4(int delta = 0) { return add(notes::b(m_octave + delta), 1); }
    Composer& c4(int delta = 0) { return add(notes::c(m_octave + delta), 1); }
    Composer& d4(int delta = 0) { return add(notes::d(m_octave + delta), 1); }
    Composer& e4(int delta = 0) { return add(notes::e(m_octave + delta), 1); }
    Composer& f4(int delta = 0) { return add(notes::f(m_octave + delta), 1); }
    Composer& g4(int delta = 0) { return add(notes::g(m_octave + delta), 1); }
    Composer& A4(int delta = 0) { return add(notes::a(m_octave + delta + 1), 1); }
    Composer& B4(int delta = 0) { return add(notes::b(m_octave + delta + 1), 1); }
    Composer& C4(int delta = 0) { return add(notes::c(m_octave + delta + 1), 1); }
    Composer& D4(int delta = 0) { return add(notes::d(m_octave + delta + 1), 1); }
    Composer& E4(int delta = 0) { return add(notes::e(m_octave + delta + 1), 1); }
    Composer& F4(int delta = 0) { return add(notes::f(m_octave + delta + 1), 1); }
    Composer& G4(int delta = 0) { return add(notes::g(m_octave + delta + 1), 1); }
    Composer& Gs4(int delta = 0) { return add(notes::g(m_octave + delta + 1).sharp(), 1); }
    Composer& a8(int delta = 0) { return add(notes::a(m_octave + delta), 0.5); }
    Composer& b8(int delta = 0) { return add(notes::b(m_octave + delta), 0.5); }
    Composer& c8(int delta = 0) { return add(notes::c(m_octave + delta), 0.5); }
    Composer& d8(int delta = 0) { return add(notes::d(m_octave + delta), 0.5); }
    Composer& e8(int delta = 0) { return add(notes::e(m_octave + delta), 0.5); }
    Composer& f8(int delta = 0) { return add(notes::f(m_octave + delta), 0.5); }
    Composer& g8(int delta = 0) { return add(notes::g(m_octave + delta), 0.5); }
    Composer& gs8(int delta = 0) { return add(notes::g(m_octave + delta).sharp(), 0.5); }
    Composer& A8(int delta = 0) { return add(notes::a(m_octave + delta + 1), 0.5); }
    Composer& B8(int delta = 0) { return add(notes::b(m_octave + delta + 1), 0.5); }
    Composer& C8(int delta = 0) { return add(notes::c(m_octave + delta + 1), 0.5); }
    Composer& D8(int delta = 0) { return add(notes::d(m_octave + delta + 1), 0.5); }
    Composer& E8(int delta = 0) { return add(notes::e(m_octave + delta + 1), 0.5); }
    Composer& F8(int delta = 0) { return add(notes::f(m_octave + delta + 1), 0.5); }
    Composer& G8(int delta = 0) { return add(notes::g(m_octave + delta + 1), 0.5); }
    Composer& Gs8(int delta = 0) { return add(notes::g(m_octave + delta + 1).sharp(), 0.5); }
    Composer& a16(int delta = 0) { return add(notes::a(m_octave + delta), 0.25); }
    Composer& b16(int delta = 0) { return add(notes::b(m_octave + delta), 0.25); }
    Composer& c16(int delta = 0) { return add(notes::c(m_octave + delta), 0.25); }
    Composer& d16(int delta = 0) { return add(notes::d(m_octave + delta), 0.25); }
    Composer& e16(int delta = 0) { return add(notes::e(m_octave + delta), 0.25); }
    Composer& f16(int delta = 0) { return add(notes::f(m_octave + delta), 0.25); }
    Composer& g16(int delta = 0) { return add(notes::g(m_octave + delta), 0.25); }
    Composer& A16(int delta = 0) { return add(notes::a(m_octave + delta + 1), 0.25); }
    Composer& B16(int delta = 0) { return add(notes::b(m_octave + delta + 1), 0.25); }
    Composer& C16(int delta = 0) { return add(notes::c(m_octave + delta + 1), 0.25); }
    Composer& D16(int delta = 0) { return add(notes::d(m_octave + delta + 1), 0.25); }
    Composer& E16(int delta = 0) { return add(notes::e(m_octave + delta + 1), 0.25); }
    Composer& F16(int delta = 0) { return add(notes::f(m_octave + delta + 1), 0.25); }
    Composer& G16(int delta = 0) { return add(notes::g(m_octave + delta + 1), 0.25); }

    Wave compose() const
    {
        return concatenate(m_waves);
    }

    void clear()
    {
        m_waves.clear();
    }
};


int main()
{
    WAVE_DATA wave_data;
    //read_wave_file("e:/temp/wave/input-16bit-44-mono.wav", &wave_data);

    //if (wave_data.n_channels != 1 || wave_data.sample_rate != 44100 || wave_data.bits_per_sample != 16)
    //{
    //    std::cerr << "Unsupported format" << std::endl;
    //    std::cerr << "Channels: " << wave_data.n_channels << std::endl;
    //    std::cerr << "Sample rate: " << wave_data.sample_rate << std::endl;
    //    std::cerr << "Bits per sample: " << wave_data.bits_per_sample << std::endl;
    //    abort();
    //}

    //auto uint8_input = wave_data.stream;
    //auto int16_input = convert_uint8_to_int16_stream(uint8_input);
    //auto double_input = convert_int16_to_double_stream(int16_input);
    //auto wave = interpolate(double_input, wave_data.sample_rate);

    //
    //auto result_wave = speed_up(wave, 1.5);

    Composer composer(120);
    composer.r16().e16().a16().C16().b16().e16().b16().D16().C8().E8().gs8().E8();
    composer.a16().e16().a16().C16().b16().e16().b16().D16().C8().a8().r4();
    composer.r16().E16().C16().E16().a16().C16().e16().g16().f8().a8().D8().F8();
    composer.F16().D16().b16().D16().g16().b16().d16().f16().e8().g8().C8().E8();
    composer.E16().C16().a16().C16().f8().D8().D16().b16().g16().b16().e8().C8();
    composer.C16().a16().f16().a16().d8().b8().C8();
    auto treble = composer.compose();

    composer.clear();
    composer.octave(2).a8().octave(3).a4().gs8().a16().e16().a16().C16().b16().e16().b16().D16();
    composer.C8().a8().gs8().e8().a16().e16().a16().C16().b16().e16().b16().D16();
    composer.C8().a8().C8().A8().D16().a16().f16().a16().d16().f16().a16(-1).c16();
    composer.b8(-1).d8().g8().b8().b16().g16().e16().g16().c16().e16().g16(-1).b16();
    composer.a8(-1).c8().d16().f16().b16(-1).d16().g8(-1).b8(-1).c16().e16().a16(-1).c16();
    composer.f8(-1).d8(-1).g16(-1).g16().f16().g16().c8();
    auto bass = composer.compose();

    auto result_wave = treble + bass;

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
