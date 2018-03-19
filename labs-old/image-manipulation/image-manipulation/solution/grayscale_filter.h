#ifndef GRAYSCALE_FILTER_H
#define GRAYSCALE_FILTER_H

#include "per_pixel_filter.h"

class GrayscaleFilter : public PerPixelFilter
{
protected:
	color process(const color&) const override;
};

#endif
