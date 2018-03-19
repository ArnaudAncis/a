#ifndef HORIZONTAL_LAYOUT_H
#define HORIZONTAL_LAYOUT_H

#include "linear-layout.h"


std::shared_ptr<Layout> create_horizontal_layout(const std::vector<std::shared_ptr<Layout>>& children, double = 5);

#endif
