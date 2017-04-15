#include "composer.h"
#include "zero-wave.h"
#include "sine-wave.h"
#include "triangle-wave.h"
#include "wave-concatenation.h"


Composer::Composer(double tempo) : m_beat_duration(60.0 / tempo), m_octave(4), m_volume(0.5) { }

Composer& Composer::rest(double beats)
{
    m_waves.push_back(zero_wave(beats * m_beat_duration));

    return *this;
}

Composer& Composer::add(Note note, double beats)
{
    auto wave = triangle_wave(beats * m_beat_duration, m_volume, note.frequency);
    m_waves.push_back(wave);

    return *this;
}

Composer& Composer::octave(int octave)
{
    m_octave = octave;

    return *this;
}

Composer& Composer::volume(double volume)
{
    m_volume = volume;

    return *this;
}

Wave Composer::compose() const
{
    return concatenate(m_waves);
}

void Composer::clear()
{
    m_waves.clear();
}

Wave treble()
{
    Composer composer(120);
    composer.r16().e16().a16().C16().b16().e16().b16().D16().C8().E8().gs8().E8();
    composer.a16().e16().a16().C16().b16().e16().b16().D16().C8().a8().r4();
    composer.r16().E16().C16().E16().a16().C16().e16().g16().f8().a8().D8().F8();
    composer.F16().D16().b16().D16().g16().b16().d16().f16().e8().g8().C8().E8();
    composer.E16().C16().a16().C16().f8().D8().D16().b16().g16().b16().e8().C8();
    composer.C16().a16().f16().a16().d8().b8().C8();

    return composer.compose();
}

Wave bass()
{
    Composer composer(120);
    composer.a8(-1).octave(3).a4().gs8().a16().e16().a16().C16().b16().e16().b16().D16();
    composer.C8().a8().gs8().e8().a16().e16().a16().C16().b16().e16().b16().D16();
    composer.C8().a8().C8().A8().D16().a16().f16().a16().d16().f16().a16(-1).c16();
    composer.b8(-1).d8().g8().b8().b16().g16().e16().g16().c16().e16().g16(-1).b16();
    composer.a8(-1).c8().d16().f16().b16(-1).d16().g8(-1).b8(-1).c16().e16().a16(-1).c16();
    composer.f8(-1).d8(-1).g16(-1).g16().f16().g16().c8();

    return composer.compose();
}