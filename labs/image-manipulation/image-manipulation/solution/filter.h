#ifndef FILTER_H
#define FILTER_H

#include "bitmap.h"
#include <memory>

class Filter
{
public:
	virtual ~Filter() { }

	virtual std::shared_ptr<Bitmap> apply(const Bitmap&) const = 0;
};

#endif