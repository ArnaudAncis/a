#ifndef LAYOUT_H
#define LAYOUT_H

#include "box.h"


class Layout
{
public:
	virtual ~Layout() { }

	virtual Box box() const = 0;
};

#endif
