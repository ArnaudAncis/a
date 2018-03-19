#ifndef MOSAIC_FILTER
#define MOSAIC_FILTER

#include "filter.h"

class MosaicFilter : public Filter
{
private:
	unsigned m_size;

public:
	MosaicFilter(unsigned size) : m_size(size) { }

	std::shared_ptr<Bitmap> apply(const Bitmap&) const override;
};

#endif
