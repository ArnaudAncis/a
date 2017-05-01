#ifndef COMPOSER_H
#define COMPOSER_H

#include "waves/wave.h"
#include "note.h"
#include <vector>
#include <functional>


class WaveFactory
{
public:
    virtual Wave create(double length, double amplitude, double frequency) = 0;
};

class ConcreteWaveFactory : public WaveFactory
{
private:
    std::function<Wave(double, double, double)> m_factory_function;

public:
    ConcreteWaveFactory(std::function<Wave(double, double, double)> factory_function)
        : m_factory_function(factory_function) { }

    Wave create(double length, double amplitude, double frequency) override
    {
        return m_factory_function(length, amplitude, frequency);
    }
};

inline std::shared_ptr<WaveFactory> wave_factory(std::function<Wave(double, double, double)> factory_function)
{
    return std::make_shared<ConcreteWaveFactory>(factory_function);
}

class Composer
{
    std::vector<Wave> m_waves;
    double m_beat_duration;
    int m_octave;
    double m_volume;
    std::shared_ptr<WaveFactory> m_wave_factory;

public:
    Composer(double tempo, std::shared_ptr<WaveFactory> wave_factory);

    Composer& rest(double beats);
    Composer& add(Note note, double beats);
    Composer& octave(int octave);
    Composer& volume(double volume);

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

    Wave compose() const;
    void clear();
};

Wave treble(std::shared_ptr<WaveFactory>);
Wave bass(std::shared_ptr<WaveFactory>);

#endif
