#include "grayscale_filter.h"

color GrayscaleFilter::process(const color& original) const
{
	double average = (original.r + original.g + original.b) / 3;

	return color(average, average, average);
}
