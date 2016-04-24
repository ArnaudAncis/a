#ifndef COLOR_FILTERS_H
#define COLOR_FILTERS_H

#include "filter.h"

class RedFilter : public Filter
{
public:
	std::shared_ptr<Bitmap> apply(const Bitmap&) const override;
};

class GreenFilter : public Filter
{
public:
	std::shared_ptr<Bitmap> apply(const Bitmap&) const override;
};

class BlueFilter : public Filter
{
public:
	std::shared_ptr<Bitmap> apply(const Bitmap&) const override;
};

#endif
