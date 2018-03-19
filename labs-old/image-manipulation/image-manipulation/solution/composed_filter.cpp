#include "composed_filter.h"

void ComposedFilter::add(std::shared_ptr<Filter> filter)
{
	this->filters.push_back(filter);
}

std::shared_ptr<Bitmap> ComposedFilter::apply(const Bitmap& original) const
{
	std::shared_ptr<Bitmap> result(nullptr);
	const Bitmap* current = &original;

	for (auto filter : this->filters)
	{
		result = filter->apply(*current);
		current = result.get();
	}

	return result;
}