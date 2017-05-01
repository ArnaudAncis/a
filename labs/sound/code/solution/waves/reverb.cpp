#include "waves/reverb.h"
#include "waves/zero-wave.h"
#include <math.h>


Wave reverb(Wave wave, unsigned n_reverberations, double factor, double delay)
{
    Wave result = zero_wave(0);

    for (unsigned i = 0; i != n_reverberations; ++i)
    {
        Wave reverberation = (wave * pow(factor, i)) >> (i * delay);
        result = result + reverberation;
    }

    return result;
}