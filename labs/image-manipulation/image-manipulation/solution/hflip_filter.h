#ifndef HFLIP_FILTER_H
#define HFLIP_FILTER_H

#include "filter.h"

class HorizontalFlipFilter : public Filter
{
public:
	std::shared_ptr<Bitmap> apply(const Bitmap&) const override;
};

#endif
