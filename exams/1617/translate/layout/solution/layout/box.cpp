#include "box.h"


Box::Box() : Box(0,0) { }

Box::Box(double width, double height)
	: width(width), height(height) { }

std::ostream& operator <<(std::ostream& out, const Box& box)
{
	return out << "Box(" << box.width << "x" << box.height << ")";
}