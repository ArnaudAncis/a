#ifndef BOX_H
#define BOX_H

#include <iostream>


struct Box
{
	Box();
	Box(double, double);

	double width;
	double height;
};

std::ostream& operator <<(std::ostream& out, const Box&);

#endif
