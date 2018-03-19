#ifndef VFLIP_FILTER_H
#define VFLIP_FILTER_H

#include "filter.h"

class VerticalFlipFilter : public Filter
{
public:
	std::shared_ptr<Bitmap> apply(const Bitmap&) const override;
};


#endif
