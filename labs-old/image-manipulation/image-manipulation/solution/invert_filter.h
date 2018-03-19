#ifndef INVERT_FILTER_H
#define INVERT_FILTER_H

#include "filter.h"

class InvertFilter : public Filter
{
public:
	std::shared_ptr<Bitmap> apply(const Bitmap&) const override;
};

#endif
