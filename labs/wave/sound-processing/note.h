#ifndef NOTE_H
#define NOTE_H

#include <math.h>


struct Note
{
    Note(double frequency) : frequency(frequency) { }

    double frequency;

    Note sharp() const { return step(1); }
    Note flat() const { return step(-1); }

    Note step(int delta) const { return Note(frequency *  pow(2, delta / 12.0)); }
    Note octave(int delta) const { return Note(frequency *  pow(2, delta)); }
};

namespace notes
{
    Note a(int octave = 4) { return Note(440.0).octave(octave - 4); }
    Note b(int octave = 4) { return a(octave).step(2); }
    Note c(int octave = 4) { return a(octave).step(-9); }
    Note d(int octave = 4) { return a(octave).step(-7); }
    Note e(int octave = 4) { return a(octave).step(-5); }
    Note f(int octave = 4) { return a(octave).step(-4); }
    Note g(int octave = 4) { return a(octave).step(-2); }
}

#endif
