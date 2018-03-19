#ifndef BLUR_FILTER_H
#define BLUR_FILTER_H

#include "filter.h"

class BlurFilter : public Filter
{
private:
	int m_distance;

public:
	BlurFilter(int distance) : m_distance(distance) { }

	std::shared_ptr<Bitmap> apply(const Bitmap&) const override;
};

#endif
