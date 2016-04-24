#include "color_filters.h"

color RedFilter::process(const color& original) const
{
	return color(original.r, 0, 0);
}

color GreenFilter::process(const color& original) const
{
	return color(0, original.g, 0);

}

color BlueFilter::process(const color& original) const
{
	return color(0, 0, original.b);
}
