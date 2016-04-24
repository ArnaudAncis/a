#ifndef COLOR_FILTERS_H
#define COLOR_FILTERS_H

#include "per_pixel_filter.h"

class RedFilter : public PerPixelFilter
{
protected:
	color process(const color&) const override;
};

class GreenFilter : public PerPixelFilter
{
protected:
	color process(const color&) const override;
};

class BlueFilter : public PerPixelFilter
{
protected:
	color process(const color&) const override;
};

#endif
