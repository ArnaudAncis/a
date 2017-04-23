#ifndef REVERB_H
#define REVERB_H

#include "waves/wave.h"


Wave reverb(Wave wave, unsigned n_reverberations, double factor, double delay);

#endif
