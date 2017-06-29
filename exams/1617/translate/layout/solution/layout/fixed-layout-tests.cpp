#include "fixed-layout.h"
#include "fixed-layout.h"
#include "Catch.h"


TEST_CASE("Fixed layout of 5x10")
{
	const Box box(10, 20);
	std::shared_ptr<Layout> layout = create_fixed_layout(box);
	Box result = layout->box();

	CHECK(result.width == Approx(box.width));
	CHECK(result.height == Approx(box.height));
}
