#ifndef GRAYSCALE_FILTER_H
#define GRAYSCALE_FILTER_H

#include "filter.h"

class GrayscaleFilter : public Filter
{
public:
	std::shared_ptr<Bitmap> apply(const Bitmap&) const override;
};

#endif
