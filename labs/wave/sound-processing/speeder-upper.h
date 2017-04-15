#ifndef SPEEDER_UPPER_H
#define SPEEDER_UPPER_H

#include "wave.h"
#include <memory>


std::shared_ptr<Wave> speed_up(std::shared_ptr<Wave>, double);

#endif
