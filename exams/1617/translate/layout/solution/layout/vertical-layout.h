#ifndef VERTICAL_LAYOUT_H
#define VERTICAL_LAYOUT_H

#include "linear-layout.h"


std::shared_ptr<Layout> create_vertical_layout(const std::vector<std::shared_ptr<Layout>>& children, double separation = 10);

#endif
