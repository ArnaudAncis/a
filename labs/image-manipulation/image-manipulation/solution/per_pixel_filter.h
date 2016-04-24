#ifndef PER_PIXEL_FILTER
#define PER_PIXEL_FILTER

#include "filter.h"

class PerPixelFilter : public Filter
{
public:
	std::shared_ptr<Bitmap> apply(const Bitmap&) const override;

protected:
	virtual color process(const color&) const = 0;
};

#endif
