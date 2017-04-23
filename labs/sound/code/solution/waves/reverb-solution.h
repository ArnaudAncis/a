#ifndef REVERB_SOLUTION_H
#define REVERB_SOLUTION_H

#include "waves/wave.h"


namespace solution
{
    Wave reverb(Wave wave, unsigned n_reverberations, double factor, double delay);
}

#endif
