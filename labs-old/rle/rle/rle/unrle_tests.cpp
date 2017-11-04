/*

TESTS

*/

#include "Catch.h"
#include "rle.h"


void unrle_test(uint8_t* input, unsigned input_size, uint8_t* expected, unsigned expected_size)
{
	auto actual = unrle(input, input_size);

	REQUIRE(expected_size == actual.size());

	for (unsigned i = 0; i != expected_size; ++i)
	{
		REQUIRE(expected[i] == actual[i]);
	}
}

TEST_CASE("unRLE on { }", "[rle]")
{
	auto result = unrle(nullptr, 0);

	REQUIRE(result.size() == 0);
}

#define ARRAY(...) { __VA_ARGS__ }
#define UNRLE_TEST(EXPECTED, INPUT) TEST_CASE("unRLE on " #INPUT, "[rle]") { uint8_t input[] = INPUT; uint8_t expected[] = EXPECTED; unrle_test(input, sizeof(input) / sizeof(uint8_t), expected, sizeof(expected) / sizeof(uint8_t)); }

UNRLE_TEST(ARRAY(1), ARRAY(1, 1))
UNRLE_TEST(ARRAY(1, 1), ARRAY(2, 1))
UNRLE_TEST(ARRAY(1, 1, 1), ARRAY(3, 1))
UNRLE_TEST(ARRAY(2), ARRAY(1, 2))
UNRLE_TEST(ARRAY(2, 2), ARRAY(2, 2))
UNRLE_TEST(ARRAY(2, 2, 2), ARRAY(3, 2))
UNRLE_TEST(ARRAY(1, 2, 3), ARRAY(1, 1, 1, 2, 1, 3))
UNRLE_TEST(ARRAY(1, 1, 2, 2, 3, 3), ARRAY(2, 1, 2, 2, 2, 3))
UNRLE_TEST(ARRAY(1, 1, 1, 2, 2, 2, 3, 3, 3), ARRAY(3, 1, 3, 2, 3, 3))
UNRLE_TEST(ARRAY(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1), ARRAY(255, 1, 47, 1));
