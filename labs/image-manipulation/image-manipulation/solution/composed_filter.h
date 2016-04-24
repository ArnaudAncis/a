#ifndef COMPOSED_FILTER_H
#define COMPOSED_FILTER_H

#include "filter.h"
#include <vector>
#include <memory>

class ComposedFilter : Filter
{
private:
	std::vector<std::shared_ptr<Filter>> filters;

public:
	void add(std::shared_ptr<Filter>);
	std::shared_ptr<Bitmap> apply(const Bitmap&) const override;
};

#endif
